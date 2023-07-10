#pragma once
#include<unordered_map>
#include<iostream>
#include<string>
#include<list>
#include"min_heap.hpp"

using namespace std;

class graph{
    public:
        unordered_map<string,list<pair<string,double>>> adj;
        unordered_map<string,bool> stations;
        int size;

    graph()
    {
        size = 0;
    }

    void add_station( string name )
    {
        stations[name] = true;
        size++;
    }

    int no_of_stations()
    {
        return size;
    }

    bool check_station( string name )
    {
        if( stations.count(name) )
            return true;

        return false;
    }

    void add_edge( string s1, string s2, double dis )
    {
        if( !check_station(s1) )
        {
            cout<<s1<<" station does not exists"<<endl;
            cout<<"Enter a valid station"<<endl;
            return;
        }

        if( !check_station(s2) )
        {
            cout<<s2<<" station does not exists"<<endl;
            cout<<"Enter a valid station"<<endl;
            return;
        }

        adj[s1].push_back({s2,dis});
        adj[s2].push_back({s1,dis});
    }

    void print_stations()
    {
        int i=1;
        int n = no_of_stations();
        cout<<"There are total "<<n<<" stations"<<endl;
        cout<<endl;
        cout<<"LIST OF ALL STATIONS:"<<endl;
        cout<<endl;
        for( auto st:stations )
        {
            cout<<i<<":"<<st.first<<endl;
            i++;
        }
        cout<<""<<endl;
    }

    void show_map()
    {
        cout<<endl;
        cout<<"LIST OF ALL TRACKS:"<<endl;
        cout<<endl;
        int i=1;
        for( auto st:stations )
        {
            string src = st.first;
            cout<<i<<":"<<"Source: "<<src<<endl;

            for( auto dest: adj[st.first] )
            {
                string desti = dest.first;
                double dist = dest.second;

                cout<<"Destination: "<<desti<<" , Dist: "<<dist<<endl; 
            }
            cout<<endl;
            i++;
        }
        cout<<endl;
    }

    void print_path( string dest, unordered_map<string,double> &dist, unordered_map<string,string> &parent )
    {
        stack<string> st;
        string node = dest;

        while( parent[node] != node )
        {
            st.push(node);
            node = parent[node];
        }
        st.push(node);


        string top = st.top();
        // double km = dist[top] - dist[parent[top]]; 
        st.pop();

        // cout<<"Source: "<<top<<" Dist: "<<km<<" -> ";
        cout<<top<<" -> ";

        //Path Printing
        while( st.size() > 1 )
        {
            top = st.top();
            // km = dist[top] - dist[parent[top]]; 
            st.pop();

            // cout<<"Station: "<<top<<" Dist: "<<km<<" -> ";
            cout<<top<<" -> ";
        }
        top = st.top();
        // km = dist[top] - dist[parent[top]]; 
        st.pop();

        // cout<<"Destination: "<<top<<" Dist: "<<km<<endl;
        cout<<top<<endl;
        cout<<"Total Distance: "<<dist[dest]<<"KM"<<endl;
        cout<<endl;
    }

    void dijkstra( string src, string dest )
    {
        if( check_station(src) && check_station(dest) )
        {
            unordered_map<string,double> dist;
            unordered_map<string,string> parent;

            for( auto st:stations )
            {
                dist[st.first] = INT_MAX;
                parent[st.first] = st.first;
            }

            min_heap<pair<double,string>> h;
            h.insert({0,src});
            dist[src] = 0;
            parent[src] = src;

            while( !h.empty() )
            {
                string node = h.top().second;
                double dis = h.top().first;
                h.pop();

                for( auto nbr:adj[node] )
                {
                    if( dist[nbr.first] > nbr.second + dis )
                    {
                        dist[nbr.first] = nbr.second + dis;
                        parent[nbr.first] = node;
                        h.insert({dist[nbr.first],nbr.first});
                    }
                }
            }

            cout<<endl;
            cout<<"THE SHORTEST PATH IS: "<<endl;
            cout<<endl;
            print_path(dest,dist,parent);
        }
        else
        {
            if( !check_station(src) )
            {
                cout<<endl;
                cout<<"SOURCE DOES NOT EXISTS!!!!!!"<<endl;
                cout<<"Enter a valid station. Check option 1"<<endl;
                cout<<endl;
            }

            if( !check_station(dest) )
            {
                cout<<endl;
                cout<<"DESTINATION DOES NOT EXISTS!!!!!!"<<endl;
                cout<<"Enter a valid station. Check option 1"<<endl;
                cout<<endl;
            }
        }

    }

};