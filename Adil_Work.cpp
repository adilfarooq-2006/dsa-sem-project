#include "FloodSystem.h"
#include <iostream>

using namespace std;

//function to load and the roads and distance
void FloodReliefSystem::loadRoads() {
    // structure: roadNetwork[SourceID].push_back({NeighborID, Distance_in_KM});

    // NORTHERN REGION (Rawalpindi, Attock, Jhelum, Mianwali)
    // Rawalpindi <-> Attock
    roadNetwork[2].push_back({14, 100});
    roadNetwork[14].push_back({2, 100});

    // Rawalpindi <-> Jhelum
    roadNetwork[2].push_back({15, 120}); 
    roadNetwork[15].push_back({2, 120});

     // Rawalpindi <-> Mianwali
    roadNetwork[2].push_back({12, 250});
    roadNetwork[12].push_back({2, 250});

    // Mianwali (12) connects the North to the West
    // Mianwali <-> Attock
    roadNetwork[12].push_back({14, 150});
    roadNetwork[14].push_back({12, 150}); 
    
    // Mianwali <-> Khushab
    roadNetwork[12].push_back({13, 80}); 
    roadNetwork[13].push_back({12, 80});

    // Mianwali <-> DG Khan
    roadNetwork[12].push_back({10, 220}); 
    roadNetwork[10].push_back({12, 220});

    // GT ROAD BELT (Jhelum -> Gujrat -> Gujranwala -> Lahore)
    // Jhelum <-> Gujrat
    roadNetwork[15].push_back({16, 60});  
    roadNetwork[16].push_back({15, 60});

    // Gujrat <-> Gujranwala
    roadNetwork[16].push_back({3, 50});   
    roadNetwork[3].push_back({16, 50});

    // Gujrat <-> Sialkot
    roadNetwork[16].push_back({5, 55});   
    roadNetwork[5].push_back({16, 55});

    // Gujranwala <-> Sialkot
    roadNetwork[3].push_back({5, 50});   
    roadNetwork[5].push_back({3, 50});

    // Gujranwala <-> Hafizabad
    roadNetwork[3].push_back({20, 55});  
    roadNetwork[20].push_back({3, 55});

    // Gujranwala <-> Lahore
    roadNetwork[3].push_back({0, 70});    
    roadNetwork[0].push_back({3, 70});

    // CENTRAL PUNJAB (Lahore, Faisalabad, Sargodha)
    // Lahore (0) Hub Connections
    // Lahore <-> Nankana Sahib
    roadNetwork[0].push_back({21, 75});  
    roadNetwork[21].push_back({0, 75});

    // Lahore <-> Kasur
    roadNetwork[0].push_back({22, 55});   
    roadNetwork[22].push_back({0, 55});

    // Lahore <-> Okara
    roadNetwork[0].push_back({19, 130});  
    roadNetwork[19].push_back({0, 130});

    // Lahore <-> Faisalabad (Motorway)
    roadNetwork[0].push_back({1, 150});   
    roadNetwork[1].push_back({0, 150});

    // Faisalabad (1) Hub Connections
    // Faisalabad <-> Nankana Sahib
    roadNetwork[1].push_back({21, 80});   
    roadNetwork[21].push_back({1, 80});

    // Faisalabad <-> Chiniot
    roadNetwork[1].push_back({11, 40});   
    roadNetwork[11].push_back({1, 40});

    // Faisalabad <-> Jhang
    roadNetwork[1].push_back({8, 75});    
    roadNetwork[8].push_back({1, 75});

    // Faisalabad <-> Toba Tek Singh
    roadNetwork[1].push_back({24, 90});   
    roadNetwork[24].push_back({1, 90});

    // Sargodha (7) Hub Connections
    // Sargodha <-> Faisalabad
    roadNetwork[7].push_back({1, 90});    
    roadNetwork[1].push_back({7, 90});

    // Sargodha <-> Chiniot
    roadNetwork[7].push_back({11, 60});   
    roadNetwork[11].push_back({7, 60});

    // Sargodha <-> Khushab
    roadNetwork[7].push_back({13, 50});   
    roadNetwork[13].push_back({7, 50});

    // Sargodha <-> Hafizabad
    roadNetwork[7].push_back({20, 100});  
    roadNetwork[20].push_back({7, 100});


    // SOUTHERN BELT (Multan, Bahawalpur, Sahiwal)
    // Multan (4) Hub Connections
    // Multan <-> Jhang
    roadNetwork[4].push_back({8, 120});   
    roadNetwork[8].push_back({4, 120});

    // Multan <-> Toba Tek Singh
    roadNetwork[4].push_back({24, 110});  
    roadNetwork[24].push_back({4, 110}); 

    // Multan <-> Vehari
    roadNetwork[4].push_back({18, 100});  
    roadNetwork[18].push_back({4, 100});

    // Multan <-> DG Khan
    roadNetwork[4].push_back({10, 130});  
    roadNetwork[10].push_back({4, 130});

    // Multan <-> Bahawalpur
    roadNetwork[4].push_back({6, 100});   
    roadNetwork[6].push_back({4, 100});

    // Sahiwal (23) Connectivity Corridor
    // Sahiwal <-> Okara
    roadNetwork[23].push_back({19, 50});  
    roadNetwork[19].push_back({23, 50});

    // Sahiwal <-> Toba Tek Singh
    roadNetwork[23].push_back({24, 85});  
    roadNetwork[24].push_back({23, 85});

    // Sahiwal <-> Pakpattan
    roadNetwork[23].push_back({9, 60});   
    roadNetwork[9].push_back({23, 60});

    // Sahiwal <-> Vehari
    roadNetwork[23].push_back({18, 100}); 
    roadNetwork[18].push_back({23, 100});


    // DEEP SOUTH (Bahawalpur, Rahim Yar Khan)
    // Bahawalpur <-> Rahim Yar Khan
    roadNetwork[6].push_back({17, 200});  
    roadNetwork[17].push_back({6, 200});

    // DG Khan <-> Rahim Yar Khan
    roadNetwork[10].push_back({17, 250}); 
    roadNetwork[17].push_back({10, 250});


    // CROSS LINKS (To ensure no dead ends)
    // Okara <-> Pakpattan
    roadNetwork[19].push_back({9, 55});   
    roadNetwork[9].push_back({19, 55});

    // Pakpattan <-> Vehari
    roadNetwork[9].push_back({18, 70});   
    roadNetwork[18].push_back({9, 70});

    // Toba Tek Singh <-> Jhang
    roadNetwork[24].push_back({8, 45});  
    roadNetwork[8].push_back({24, 45});

}