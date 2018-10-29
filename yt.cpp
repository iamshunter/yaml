#include <iostream>
#include <stdio.h>
#include "yaml.h"

using namespace YAML;
using namespace std;
int main(int argc, char *argv[])
{

    char bigBuf[4096]={0};
    int  nn;
    FILE *fptr = fopen("config.yaml", "r");
    nn=fread(bigBuf, 1, sizeof(bigBuf), fptr);
    printf("Read %d bytes\n%s\n", nn, bigBuf);
    fclose(fptr);

    YAML::Node node = YAML::Load(bigBuf);
    //YAML::Node node = YAML::LoadFile("config.yaml");
    YAML::Node american = node["american"];
    YAML::Node national = node["national"];

    if ( argc != 4 )
    {
        cout << "I need 4 args" << endl;
        cout << "e.g. "<< argv[0] << " CMDL Vortex T2" << endl;
        return -1;
    }
    Node cmdl = node[argv[1]];
    Node vort = node[argv[2]];
    Node mt2  = node[argv[3]];

    printf("Type %x\n", node.Type());

    if ( node["american"] )
    {
       printf("american\n");
       for ( int ii = 0; ii < american.size(); ii++ )
       {
           cout << "american ::" << ii << " " << american[ii].as<string>() << endl;
       }
    }

    if ( node["national"] )
    {
       printf("national\n");
       for ( int ii = 0; ii < national.size(); ii++ )
       {
           cout << "national ::" << ii << " " << national[ii].as<string>() << endl;
       }
    }

    YAML::Node tempNode;
    for ( int arg=1; arg<4; arg++ )
    {
       if ( node[argv[arg]] )
       {
          tempNode = node[argv[arg]];
          cout << "Node name " << argv[arg] << "size " << tempNode.size() << " " << endl;
          cout << "Freq -- : int " << tempNode["freq"].as<int>()    << endl;
          cout << "band -- : str " << tempNode["band"].as<string>() << endl;
       }
    }

}
