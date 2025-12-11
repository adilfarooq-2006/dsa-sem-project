#include "FloodSystem.h"
#include <iostream>
#include <climits>

using namespace std;

// =====================================================
// AHMED — LOAD CITIES INTO HASHMAP (unordered_map)
// =====================================================
void FloodReliefSystem::loadCities() {
    cityDatabase[0] = {0, "Ahmadpur Sial", 8, true, true, 82, INT_MAX, -1};
    cityDatabase[1] = {1, "Ahmedpur East", 7, true, false, 19, INT_MAX, -1};
    cityDatabase[2] = {2, "Alipur Chatha", 25, false, false, 26, INT_MAX, -1};
    cityDatabase[3] = {3, "Arifwala", 23, false, false, 33, INT_MAX, -1};
    cityDatabase[4] = {4, "Attock Tehsil", 26, true, true, 41, INT_MAX, -1};
    cityDatabase[5] = {5, "Baddomalhi", 22, false, true, 68, INT_MAX, -1};
    cityDatabase[6] = {6, "Bahawalnagar", 5, false, true, 39, INT_MAX, -1};
    cityDatabase[7] = {7, "Bahawalpur", 23, false, true, 34, INT_MAX, -1};
    cityDatabase[8] = {8, "Bakhri Ahmad Khan", 21, false, false, 86, INT_MAX, -1};
    cityDatabase[9] = {9, "Basirpur", 5, true, true, 59, INT_MAX, -1};
    cityDatabase[10] = {10, "Basti Dosa", 20, false, false, 11, INT_MAX, -1};
    cityDatabase[11] = {11, "Begowala", 12, true, true, 0, INT_MAX, -1};
    cityDatabase[12] = {12, "Bhakkar", 23, false, true, 33, INT_MAX, -1};
    cityDatabase[13] = {13, "Bhalwal", 25, true, false, 37, INT_MAX, -1};
    cityDatabase[14] = {14, "Bhawana", 29, true, true, 27, INT_MAX, -1};
    cityDatabase[15] = {15, "Bhera", 23, true, false, 98, INT_MAX, -1};
    cityDatabase[16] = {16, "Bhopalwala", 7, true, false, 63, INT_MAX, -1};
    cityDatabase[17] = {17, "Burewala", 2, true, false, 86, INT_MAX, -1};
    cityDatabase[18] = {18, "Chak Azam Saffo", 18, true, false, 83, INT_MAX, -1};
    cityDatabase[19] = {19, "Chak Jhumra", 16, true, true, 44, INT_MAX, -1};
    cityDatabase[20] = {20, "Chak One Hundred Twenty Nine Left", 17, true, false, 66, INT_MAX, -1};
    cityDatabase[21] = {21, "Chak Thirty-one -Eleven Left", 15, false, true, 43, INT_MAX, -1};
    cityDatabase[22] = {22, "Chak Two Hundred Forty-Nine TDA", 18, false, true, 98, INT_MAX, -1};
    cityDatabase[23] = {23, "Chakwal", 16, false, true, 37, INT_MAX, -1};
    cityDatabase[24] = {24, "Chawinda", 11, true, false, 70, INT_MAX, -1};
    cityDatabase[25] = {25, "Chichawatni", 1, true, false, 29, INT_MAX, -1};
    cityDatabase[26] = {26, "Chiniot", 6, false, false, 1, INT_MAX, -1};
    cityDatabase[27] = {27, "Chishtian", 29, true, false, 61, INT_MAX, -1};
    cityDatabase[28] = {28, "Choa Saidanshah", 10, false, true, 70, INT_MAX, -1};
    cityDatabase[29] = {29, "Chuhar Kana", 24, false, true, 50, INT_MAX, -1};
    cityDatabase[30] = {30, "Chunian", 5, false, false, 95, INT_MAX, -1};
    cityDatabase[31] = {31, "Daira Din Panah", 17, false, false, 18, INT_MAX, -1};
    cityDatabase[32] = {32, "Dajal", 9, false, true, 56, INT_MAX, -1};
    cityDatabase[33] = {33, "Dandot RS", 22, false, true, 1, INT_MAX, -1};
    cityDatabase[34] = {34, "Darya Khan", 1, false, false, 90, INT_MAX, -1};
    cityDatabase[35] = {35, "Daska", 23, true, true, 47, INT_MAX, -1};
    cityDatabase[36] = {36, "Daud Khel", 12, false, false, 53, INT_MAX, -1};
    cityDatabase[37] = {37, "Daultala", 24, true, false, 32, INT_MAX, -1};
    cityDatabase[38] = {38, "Dera Ghazi Khan", 24, true, true, 33, INT_MAX, -1};
    cityDatabase[39] = {39, "Dhanot", 0, false, false, 12, INT_MAX, -1};
    cityDatabase[40] = {40, "Dhaunkal", 9, true, false, 95, INT_MAX, -1};
    cityDatabase[41] = {41, "Dhok Awan", 10, true, false, 48, INT_MAX, -1};
    cityDatabase[42] = {42, "Dijkot", 13, true, false, 12, INT_MAX, -1};
    cityDatabase[43] = {43, "Dinan Bashnoian Wala", 8, true, true, 42, INT_MAX, -1};
    cityDatabase[44] = {44, "Dinga", 13, true, true, 12, INT_MAX, -1};
    cityDatabase[45] = {45, "Dipalpur", 4, false, false, 59, INT_MAX, -1};
    cityDatabase[46] = {46, "Dullewala", 17, true, true, 54, INT_MAX, -1};
    cityDatabase[47] = {47, "Dunga Bunga", 9, true, true, 45, INT_MAX, -1};
    cityDatabase[48] = {48, "Dunyapur", 1, true, false, 44, INT_MAX, -1};
    cityDatabase[49] = {49, "Eminabad", 12, false, true, 45, INT_MAX, -1};
    cityDatabase[50] = {50, "Faisalabad", 4, true, true, 26, INT_MAX, -1};
    cityDatabase[51] = {51, "Faqirwali", 24, false, true, 24, INT_MAX, -1};
    cityDatabase[52] = {52, "Faruka", 24, false, true, 49, INT_MAX, -1};
    cityDatabase[53] = {53, "Fazilpur", 30, false, true, 46, INT_MAX, -1};
    cityDatabase[54] = {54, "Ferozewala", 17, true, false, 31, INT_MAX, -1};
    cityDatabase[55] = {55, "Fort Abbas", 0, true, false, 35, INT_MAX, -1};
    cityDatabase[56] = {56, "Garh Maharaja", 2, true, false, 66, INT_MAX, -1};
    cityDatabase[57] = {57, "Gojra", 20, false, true, 86, INT_MAX, -1};
    cityDatabase[58] = {58, "Gujar Khan", 12, true, true, 6, INT_MAX, -1};
    cityDatabase[59] = {59, "Gujranwala", 17, false, false, 61, INT_MAX, -1};
    cityDatabase[60] = {60, "Gujrat", 1, true, false, 77, INT_MAX, -1};
    cityDatabase[61] = {61, "Hadali", 23, true, true, 83, INT_MAX, -1};
    cityDatabase[62] = {62, "Hafizabad", 7, false, true, 88, INT_MAX, -1};
    cityDatabase[63] = {63, "Harnoli", 6, true, true, 46, INT_MAX, -1};
    cityDatabase[64] = {64, "Harunabad", 23, false, false, 39, INT_MAX, -1};
    cityDatabase[65] = {65, "Hasan Abdal", 30, true, false, 12, INT_MAX, -1};
    cityDatabase[66] = {66, "Hasilpur", 19, true, true, 9, INT_MAX, -1};
    cityDatabase[67] = {67, "Haveli Lakha", 25, true, false, 67, INT_MAX, -1};
    cityDatabase[68] = {68, "Hazro", 7, false, true, 8, INT_MAX, -1};
    cityDatabase[69] = {69, "Hujra Shah Muqeem", 17, true, true, 75, INT_MAX, -1};
    cityDatabase[70] = {70, "Jahanian Shah", 12, true, true, 55, INT_MAX, -1};
    cityDatabase[71] = {71, "Jalalpur Jattan", 30, false, true, 69, INT_MAX, -1};
    cityDatabase[72] = {72, "Jalalpur Pirwala", 20, false, true, 14, INT_MAX, -1};
    cityDatabase[73] = {73, "Jampur", 1, true, false, 95, INT_MAX, -1};
    cityDatabase[74] = {74, "Jand", 9, false, true, 14, INT_MAX, -1};
    cityDatabase[75] = {75, "Jandiala Sher Khan", 25, false, false, 46, INT_MAX, -1};
    cityDatabase[76] = {76, "Jaranwala", 16, true, true, 67, INT_MAX, -1};
    cityDatabase[77] = {77, "Jatoi Shimali", 5, false, false, 55, INT_MAX, -1};
    cityDatabase[78] = {78, "Jauharabad", 0, true, false, 47, INT_MAX, -1};
    cityDatabase[79] = {79, "Jhang", 22, false, true, 18, INT_MAX, -1};
    cityDatabase[80] = {80, "Jhang Sadar", 2, true, false, 2, INT_MAX, -1};
    cityDatabase[81] = {81, "Jhawarian", 25, true, true, 30, INT_MAX, -1};
    cityDatabase[82] = {82, "Jhelum", 27, true, false, 100, INT_MAX, -1};
    cityDatabase[83] = {83, "Kabirwala", 1, true, false, 56, INT_MAX, -1};
    cityDatabase[84] = {84, "Kahna Nau", 22, false, true, 0, INT_MAX, -1};
    cityDatabase[85] = {85, "Kahuta", 15, false, false, 84, INT_MAX, -1};
    cityDatabase[86] = {86, "Kalabagh", 13, false, true, 75, INT_MAX, -1};
    cityDatabase[87] = {87, "Kalaswala", 6, false, false, 9, INT_MAX, -1};
    cityDatabase[88] = {88, "Kaleke Mandi", 11, false, false, 41, INT_MAX, -1};
    cityDatabase[89] = {89, "Kallar Kahar", 14, false, true, 43, INT_MAX, -1};
    cityDatabase[90] = {90, "Kalur Kot", 23, true, false, 88, INT_MAX, -1};
    cityDatabase[91] = {91, "Kamalia", 10, true, true, 73, INT_MAX, -1};
    cityDatabase[92] = {92, "Kamar Mushani", 15, true, true, 42, INT_MAX, -1};
    cityDatabase[93] = {93, "Kamoke", 9, true, false, 40, INT_MAX, -1};
    cityDatabase[94] = {94, "Kamra", 3, false, true, 82, INT_MAX, -1};
    cityDatabase[95] = {95, "Kanganpur", 6, false, false, 45, INT_MAX, -1};
    cityDatabase[96] = {96, "Karor", 29, false, true, 70, INT_MAX, -1};
    cityDatabase[97] = {97, "Kasur", 15, true, false, 100, INT_MAX, -1};
    cityDatabase[98] = {98, "Keshupur", 11, false, true, 48, INT_MAX, -1};
    cityDatabase[99] = {99, "Khairpur Tamiwali", 21, true, false, 14, INT_MAX, -1};
    cityDatabase[100] = {100, "Khandowa", 12, false, false, 19, INT_MAX, -1};
    cityDatabase[101] = {101, "Khanewal", 10, true, true, 0, INT_MAX, -1};
    cityDatabase[102] = {102, "Khanga Dogran", 8, true, true, 44, INT_MAX, -1};
    cityDatabase[103] = {103, "Khangarh", 10, true, true, 51, INT_MAX, -1};
    cityDatabase[104] = {104, "Khanpur", 15, false, false, 7, INT_MAX, -1};
    cityDatabase[105] = {105, "Kharian", 18, false, true, 10, INT_MAX, -1};
    cityDatabase[106] = {106, "Khewra", 18, false, true, 50, INT_MAX, -1};
    cityDatabase[107] = {107, "Khurrianwala", 13, false, true, 86, INT_MAX, -1};
    cityDatabase[108] = {108, "Khushab", 22, false, false, 54, INT_MAX, -1};
    cityDatabase[109] = {109, "Kohror Pakka", 12, true, true, 62, INT_MAX, -1};
    cityDatabase[110] = {110, "Kot Addu Tehsil", 8, false, true, 54, INT_MAX, -1};
    cityDatabase[111] = {111, "Kot Ghulam Muhammad", 2, false, true, 20, INT_MAX, -1};
    cityDatabase[112] = {112, "Kot Mumin", 29, false, false, 54, INT_MAX, -1};
    cityDatabase[113] = {113, "Kot Radha Kishan", 16, false, false, 95, INT_MAX, -1};
    cityDatabase[114] = {114, "Kot Rajkour", 23, false, true, 70, INT_MAX, -1};
    cityDatabase[115] = {115, "Kot Samaba", 26, true, true, 51, INT_MAX, -1};
    cityDatabase[116] = {116, "Kot Sultan", 19, false, true, 74, INT_MAX, -1};
    cityDatabase[117] = {117, "Kotli Loharan", 3, true, true, 84, INT_MAX, -1};
    cityDatabase[118] = {118, "Kundian", 4, true, true, 32, INT_MAX, -1};
    cityDatabase[119] = {119, "Kunjah", 29, false, false, 17, INT_MAX, -1};
    cityDatabase[120] = {120, "Ladhewala Waraich", 7, false, false, 32, INT_MAX, -1};
    cityDatabase[121] = {121, "Lahore", 26, true, true, 9, INT_MAX, -1};
    cityDatabase[122] = {122, "Lala Musa", 5, false, true, 96, INT_MAX, -1};
    cityDatabase[123] = {123, "Lalian", 10, false, true, 77, INT_MAX, -1};
    cityDatabase[124] = {124, "Layyah", 24, true, false, 24, INT_MAX, -1};
    cityDatabase[125] = {125, "Liliani", 10, true, false, 31, INT_MAX, -1};
    cityDatabase[126] = {126, "Lodhran", 8, false, true, 86, INT_MAX, -1};
    cityDatabase[127] = {127, "Mailsi", 19, true, false, 16, INT_MAX, -1};
    cityDatabase[128] = {128, "Malakwal", 8, true, false, 76, INT_MAX, -1};
    cityDatabase[129] = {129, "Malakwal City", 27, true, false, 0, INT_MAX, -1};
    cityDatabase[130] = {130, "Mamu Kanjan", 9, true, true, 9, INT_MAX, -1};
    cityDatabase[131] = {131, "Mananwala", 24, false, true, 94, INT_MAX, -1};
    cityDatabase[132] = {132, "Mandi Bahauddin", 4, false, false, 6, INT_MAX, -1};
    cityDatabase[133] = {133, "Mangla", 2, true, true, 73, INT_MAX, -1};
    cityDatabase[134] = {134, "Mankera", 9, true, false, 82, INT_MAX, -1};
    cityDatabase[135] = {135, "Mehmand Chak", 26, false, true, 80, INT_MAX, -1};
    cityDatabase[136] = {136, "Mian Channun", 18, true, false, 46, INT_MAX, -1};
    cityDatabase[137] = {137, "Mianke Mor", 23, true, true, 10, INT_MAX, -1};
    cityDatabase[138] = {138, "Mianwali", 16, true, false, 52, INT_MAX, -1};
    cityDatabase[139] = {139, "Minchinabad", 9, true, true, 14, INT_MAX, -1};
    cityDatabase[140] = {140, "Mitha Tiwana", 4, true, true, 83, INT_MAX, -1};
    cityDatabase[141] = {141, "Moza Shahwala", 24, false, true, 47, INT_MAX, -1};
    cityDatabase[142] = {142, "Multan", 16, true, true, 26, INT_MAX, -1};
    cityDatabase[143] = {143, "Muridke", 30, false, true, 50, INT_MAX, -1};
    cityDatabase[144] = {144, "Murree", 14, false, true, 46, INT_MAX, -1};
    cityDatabase[145] = {145, "Mustafabad", 30, false, false, 12, INT_MAX, -1};
    cityDatabase[146] = {146, "Muzaffargarh", 27, true, true, 42, INT_MAX, -1};
    cityDatabase[147] = {147, "Nankana Sahib", 25, true, false, 38, INT_MAX, -1};
    cityDatabase[148] = {148, "Narang Mandi", 18, false, false, 95, INT_MAX, -1};
    cityDatabase[149] = {149, "Narowal", 19, false, true, 43, INT_MAX, -1};
    cityDatabase[150] = {150, "Naushahra Virkan", 25, true, true, 94, INT_MAX, -1};
    cityDatabase[151] = {151, "Nazir Town", 24, false, true, 68, INT_MAX, -1};
    cityDatabase[152] = {152, "Okara", 8, true, false, 57, INT_MAX, -1};
    cityDatabase[153] = {153, "Pakki Shagwanwali", 1, true, true, 5, INT_MAX, -1};
    cityDatabase[154] = {154, "Pakpattan", 28, false, false, 3, INT_MAX, -1};
    cityDatabase[155] = {155, "Pasrur", 0, false, true, 76, INT_MAX, -1};
    cityDatabase[156] = {156, "Pattoki", 8, false, true, 73, INT_MAX, -1};
    cityDatabase[157] = {157, "Phalia", 10, false, false, 70, INT_MAX, -1};
    cityDatabase[158] = {158, "Pind Dadan Khan", 4, false, true, 53, INT_MAX, -1};
    cityDatabase[159] = {159, "Pindi Bhattian", 6, true, false, 26, INT_MAX, -1};
    cityDatabase[160] = {160, "Pindi Gheb", 8, true, true, 42, INT_MAX, -1};
    cityDatabase[161] = {161, "Pir Mahal", 12, true, false, 82, INT_MAX, -1};
    cityDatabase[162] = {162, "Qadirpur Ran", 13, true, false, 24, INT_MAX, -1};
    cityDatabase[163] = {163, "Qila Didar Singh", 19, true, false, 93, INT_MAX, -1};
    cityDatabase[164] = {164, "Rabwah", 10, false, false, 13, INT_MAX, -1};
    cityDatabase[165] = {165, "Rahim Yar Khan", 7, true, true, 6, INT_MAX, -1};
    cityDatabase[166] = {166, "Raiwind", 0, true, true, 25, INT_MAX, -1};
    cityDatabase[167] = {167, "Raja Jang", 11, false, false, 75, INT_MAX, -1};
    cityDatabase[168] = {168, "Rajanpur", 16, true, true, 45, INT_MAX, -1};
    cityDatabase[169] = {169, "Rasulnagar", 1, false, true, 45, INT_MAX, -1};
    cityDatabase[170] = {170, "Rawalpindi", 0, false, true, 50, INT_MAX, -1};
    cityDatabase[171] = {171, "Renala Khurd", 20, false, false, 66, INT_MAX, -1};
    cityDatabase[172] = {172, "Rojhan", 14, false, true, 81, INT_MAX, -1};
    cityDatabase[173] = {173, "Sadiqabad", 23, false, true, 28, INT_MAX, -1};
    cityDatabase[174] = {174, "Sahiwal", 2, true, false, 55, INT_MAX, -1};
    cityDatabase[175] = {175, "Sambrial", 26, true, false, 25, INT_MAX, -1};
    cityDatabase[176] = {176, "Sangla Hill", 22, true, true, 54, INT_MAX, -1};
    cityDatabase[177] = {177, "Sanjwal", 20, false, false, 59, INT_MAX, -1};
    cityDatabase[178] = {178, "Sarai Alamgir", 2, true, false, 17, INT_MAX, -1};
    cityDatabase[179] = {179, "Sarai Sidhu", 22, false, false, 70, INT_MAX, -1};
    cityDatabase[180] = {180, "Sargodha", 30, false, false, 60, INT_MAX, -1};
    cityDatabase[181] = {181, "Shahkot Tehsil", 1, false, false, 43, INT_MAX, -1};
    cityDatabase[182] = {182, "Shahpur", 3, false, true, 72, INT_MAX, -1};
    cityDatabase[183] = {183, "Shahr Sultan", 6, true, false, 1, INT_MAX, -1};
    cityDatabase[184] = {184, "Shakargarh", 11, true, true, 21, INT_MAX, -1};
    cityDatabase[185] = {185, "Sharqpur", 9, true, true, 39, INT_MAX, -1};
    cityDatabase[186] = {186, "Sheikhupura", 4, true, false, 34, INT_MAX, -1};
    cityDatabase[187] = {187, "Shorkot", 25, true, false, 61, INT_MAX, -1};
    cityDatabase[188] = {188, "Shujaabad", 1, false, true, 84, INT_MAX, -1};
    cityDatabase[189] = {189, "Sialkot", 6, false, false, 1, INT_MAX, -1};
    cityDatabase[190] = {190, "Sillanwali", 22, true, false, 100, INT_MAX, -1};
    cityDatabase[191] = {191, "Sodhra", 8, false, true, 17, INT_MAX, -1};
    cityDatabase[192] = {192, "Sukheke Mandi", 13, false, false, 68, INT_MAX, -1};
    cityDatabase[193] = {193, "Surkhpur", 25, false, false, 9, INT_MAX, -1};
    cityDatabase[194] = {194, "Talagang", 26, true, true, 65, INT_MAX, -1};
    cityDatabase[195] = {195, "Talamba", 20, true, true, 39, INT_MAX, -1};
    cityDatabase[196] = {196, "Tandlianwala", 18, true, false, 60, INT_MAX, -1};
    cityDatabase[197] = {197, "Taunsa", 16, true, false, 38, INT_MAX, -1};
    cityDatabase[198] = {198, "Toba Tek Singh", 8, true, false, 88, INT_MAX, -1};
    cityDatabase[199] = {199, "Vihari", 11, true, true, 66, INT_MAX, -1};
    cityDatabase[200] = {200, "Wah", 14, false, false, 44, INT_MAX, -1};
    cityDatabase[201] = {201, "Warburton", 1, true, false, 14, INT_MAX, -1};
    cityDatabase[202] = {202, "Wazirabad", 19, true, true, 17, INT_MAX, -1};
    cityDatabase[203] = {203, "Yazman", 3, false, true, 27, INT_MAX, -1};


    cout << "[Ahmed] Data: 203 Cities Loaded into HashMap." << endl;
}

// =====================================================
// UPDATE CITY STATUS
// =====================================================
void FloodReliefSystem::updateCityStatus(int id) {
    auto it = cityDatabase.find(id);

    if (it != cityDatabase.end()) {
        City &city = it->second;

        city.hasReceivedAid = true;
        city.isFlooded = false;
        city.injuredCount = 0;
        city.priorityScore = 0;

        cout << "[Update] " << city.name << " is now SAFE." << endl;
    }
    else {
        cout << "[Error] City ID " << id << " not found in HashMap!" << endl;
    }
}

// =====================================================
// EVAPORATION OF FLOOD EFFECT
// =====================================================
void FloodReliefSystem::evaporateFlood() {
    cout << "[Nature] Flood waters are receding..." << endl;

    // HashMap iterates in random bucket order
    for (auto &entry : cityDatabase) {
        City &city = entry.second;

        if (city.isFlooded && city.injuredCount > 0) {
            city.injuredCount--;
        }
    }
}

// =====================================================
// FETCH A CITY (SAFE HASHMAP ACCESS)
// =====================================================
City FloodReliefSystem::getCity(int id) {
    // If not found → return an empty city instead of crashing
    if (cityDatabase.find(id) != cityDatabase.end()) {
        return cityDatabase[id];
    }

    cout << "[Warning] Attempted to get invalid city ID: " << id << endl;
    return City();
}
