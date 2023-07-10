#include<bits/stdc++.h>
#include"graph.hpp"
#include"min_heap.hpp"

using namespace std;

int main()
{
    //ENTER F8 to run in external cmd
    graph g;

    g.add_station("Motera");
    g.add_station("Vishwakarma");
    g.add_station("Tapovan");
    g.add_station("GNLU");
    g.add_station("Chiloda");
    g.add_station("GIFT_CITY");
    g.add_station("PDPU");
    g.add_station("INFO_CITY");
    g.add_station("Kalol");
    g.add_station("Mahatma_Mandir");
    g.add_station("Akshardham");
    g.add_station("Sector_16");
    g.add_station("Sector_24");


    g.add_edge("Motera","Vishwakarma",1.4);
    g.add_edge("Vishwakarma","Tapovan",2.4);
    g.add_edge("Tapovan","GIFT_CITY",16);
    g.add_edge("Motera","GNLU",12);
    g.add_edge("GNLU","GIFT_CITY",6);
    g.add_edge("GNLU","PDPU",1);
    g.add_edge("GIFT_CITY","PDPU",5.8);
    g.add_edge("INFO_CITY","PDPU",7.3);
    g.add_edge("INFO_CITY","Kalol",20);
    g.add_edge("INFO_CITY","Akshardham",7);
    g.add_edge("Akshardham","Chiloda",8);
    g.add_edge("Akshardham","Sector_16",4);
    g.add_edge("Sector_16","Sector_24",2);
    g.add_edge("Sector_24","Mahatma_Mandir",2);
    g.add_edge("Mahatma_Mandir","Kalol",19);
    g.add_edge("Chiloda","GIFT_CITY",8);

    int choice;
    string src, dest;
    bool flag = true;

    do
    {
        cout<<"**********PATH FINDER**********"<<endl;
        cout<<endl;

        cout<<"1: List all stations"<<endl;
        cout<<"2: List all station routes"<<endl;
        cout<<"3: Shortest Path from Source to Destination"<<endl;
        cout<<"4: Exit"<<endl;
        cout<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
            case 1: 
                g.print_stations();
                break;

            case 2:
                g.show_map();
                break;

            case 3:
                cout<<"Enter Source: ";
                cin>>src;
                cout<<endl;
                cout<<"Enter Destination: ";
                cin>>dest;
                g.dijkstra(src,dest);
                break;
            
            case 4:
                flag = false;
                break;

            default:
                cout<<"INVALID CHOICE!!!"<<endl;
                cout<<"Choose a number between 1 to 4"<<endl;
        }
    } while(flag);

    return 0;
}