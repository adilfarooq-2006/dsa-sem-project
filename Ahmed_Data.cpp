#include "FloodSystem.h"
#include <iostream>
#include <climits>

using namespace std;

// =====================================================
// AHMED — LOAD CITIES INTO HASHMAP (unordered_map)
// =====================================================
void FloodReliefSystem::loadCities() {
    cityDatabase[0] = {0, "Ahmadpur Sial", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[1] = {1, "Ahmedpur East", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[2] = {2, "Alipur Chatha", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[3] = {3, "Arifwala", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[4] = {4, "Attock Tehsil", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[5] = {5, "Baddomalhi", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[6] = {6, "Bahawalnagar", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[7] = {7, "Bahawalpur", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[8] = {8, "Bakhri Ahmad Khan", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[9] = {9, "Basirpur", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[10] = {10, "Basti Dosa", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[11] = {11, "Begowala", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[12] = {12, "Bhakkar", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[13] = {13, "Bhalwal", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[14] = {14, "Bhawana", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[15] = {15, "Bhera", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[16] = {16, "Bhopalwala", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[17] = {17, "Burewala", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[18] = {18, "Chak Azam Saffo", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[19] = {19, "Chak Jhumra", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[20] = {20, "Chak One Hundred Twenty Nine Left", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[21] = {21, "Chak Thirty-one -Eleven Left", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[22] = {22, "Chak Two Hundred Forty-Nine TDA", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[23] = {23, "Chakwal", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[24] = {24, "Chawinda", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[25] = {25, "Chichawatni", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[26] = {26, "Chiniot", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[27] = {27, "Chishtian", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[28] = {28, "Choa Saidanshah", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[29] = {29, "Chuhar Kana", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[30] = {30, "Chunian", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[31] = {31, "Daira Din Panah", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[32] = {32, "Dajal", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[33] = {33, "Dandot RS", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[34] = {34, "Darya Khan", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[35] = {35, "Daska", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[36] = {36, "Daud Khel", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[37] = {37, "Daultala", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[38] = {38, "Dera Ghazi Khan", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[39] = {39, "Dhanot", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[40] = {40, "Dhaunkal", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[41] = {41, "Dhok Awan", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[42] = {42, "Dijkot", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[43] = {43, "Dinan Bashnoian Wala", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[44] = {44, "Dinga", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[45] = {45, "Dipalpur", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[46] = {46, "Dullewala", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[47] = {47, "Dunga Bunga", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[48] = {48, "Dunyapur", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[49] = {49, "Eminabad", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[50] = {50, "Faisalabad", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[51] = {51, "Faqirwali", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[52] = {52, "Faruka", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[53] = {53, "Fazilpur", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[54] = {54, "Ferozewala", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[55] = {55, "Fort Abbas", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[56] = {56, "Garh Maharaja", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[57] = {57, "Gojra", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[58] = {58, "Gujar Khan", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[59] = {59, "Gujranwala", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[60] = {60, "Gujrat", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[61] = {61, "Hadali", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[62] = {62, "Hafizabad", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[63] = {63, "Harnoli", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[64] = {64, "Harunabad", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[65] = {65, "Hasan Abdal", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[66] = {66, "Hasilpur", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[67] = {67, "Haveli Lakha", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[68] = {68, "Hazro", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[69] = {69, "Hujra Shah Muqeem", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[70] = {70, "Jahanian Shah", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[71] = {71, "Jalalpur Jattan", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[72] = {72, "Jalalpur Pirwala", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[73] = {73, "Jampur", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[74] = {74, "Jand", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[75] = {75, "Jandiala Sher Khan", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[76] = {76, "Jaranwala", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[77] = {77, "Jatoi Shimali", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[78] = {78, "Jauharabad", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[79] = {79, "Jhang", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[80] = {80, "Jhang Sadar", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[81] = {81, "Jhawarian", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[82] = {82, "Jhelum", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[83] = {83, "Kabirwala", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[84] = {84, "Kahna Nau", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[85] = {85, "Kahuta", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[86] = {86, "Kalabagh", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[87] = {87, "Kalaswala", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[88] = {88, "Kaleke Mandi", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[89] = {89, "Kallar Kahar", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[90] = {90, "Kalur Kot", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[91] = {91, "Kamalia", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[92] = {92, "Kamar Mushani", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[93] = {93, "Kamoke", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[94] = {94, "Kamra", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[95] = {95, "Kanganpur", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[96] = {96, "Karor", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[97] = {97, "Kasur", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[98] = {98, "Keshupur", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[99] = {99, "Khairpur Tamiwali", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[100] = {100, "Khandowa", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[101] = {101, "Khanewal", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[102] = {102, "Khanga Dogran", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[103] = {103, "Khangarh", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[104] = {104, "Khanpur", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[105] = {105, "Kharian", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[106] = {106, "Khewra", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[107] = {107, "Khurrianwala", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[108] = {108, "Khushab", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[109] = {109, "Kohror Pakka", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[110] = {110, "Kot Addu Tehsil", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[111] = {111, "Kot Ghulam Muhammad", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[112] = {112, "Kot Mumin", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[113] = {113, "Kot Radha Kishan", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[114] = {114, "Kot Rajkour", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[115] = {115, "Kot Samaba", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[116] = {116, "Kot Sultan", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[117] = {117, "Kotli Loharan", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[118] = {118, "Kundian", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[119] = {119, "Kunjah", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[120] = {120, "Ladhewala Waraich", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[121] = {121, "Lahore", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[122] = {122, "Lala Musa", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[123] = {123, "Lalian", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[124] = {124, "Layyah", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[125] = {125, "Liliani", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[126] = {126, "Lodhran", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[127] = {127, "Mailsi", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[128] = {128, "Malakwal", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[129] = {129, "Malakwal City", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[130] = {130, "Mamu Kanjan", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[131] = {131, "Mananwala", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[132] = {132, "Mandi Bahauddin", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[133] = {133, "Mangla", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[134] = {134, "Mankera", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[135] = {135, "Mehmand Chak", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[136] = {136, "Mian Channun", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[137] = {137, "Mianke Mor", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[138] = {138, "Mianwali", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[139] = {139, "Minchinabad", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[140] = {140, "Mitha Tiwana", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[141] = {141, "Moza Shahwala", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[142] = {142, "Multan", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[143] = {143, "Muridke", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[144] = {144, "Murree", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[145] = {145, "Mustafabad", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[146] = {146, "Muzaffargarh", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[147] = {147, "Nankana Sahib", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[148] = {148, "Narang Mandi", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[149] = {149, "Narowal", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[150] = {150, "Naushahra Virkan", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[151] = {151, "Nazir Town", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[152] = {152, "Okara", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[153] = {153, "Pakki Shagwanwali", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[154] = {154, "Pakpattan", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[155] = {155, "Pasrur", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[156] = {156, "Pattoki", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[157] = {157, "Phalia", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[158] = {158, "Pind Dadan Khan", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[159] = {159, "Pindi Bhattian", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[160] = {160, "Pindi Gheb", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[161] = {161, "Pir Mahal", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[162] = {162, "Qadirpur Ran", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[163] = {163, "Qila Didar Singh", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[164] = {164, "Rabwah", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[165] = {165, "Rahim Yar Khan", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[166] = {166, "Raiwind", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[167] = {167, "Raja Jang", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[168] = {168, "Rajanpur", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[169] = {169, "Rasulnagar", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[170] = {170, "Rawalpindi", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[171] = {171, "Renala Khurd", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[172] = {172, "Rojhan", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[173] = {173, "Sadiqabad", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[174] = {174, "Sahiwal", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[175] = {175, "Sambrial", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[176] = {176, "Sangla Hill", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[177] = {177, "Sanjwal", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[178] = {178, "Sarai Alamgir", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[179] = {179, "Sarai Sidhu", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[180] = {180, "Sargodha", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[181] = {181, "Shahkot Tehsil", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[182] = {182, "Shahpur", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[183] = {183, "Shahr Sultan", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[184] = {184, "Shakargarh", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[185] = {185, "Sharqpur", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[186] = {186, "Sheikhupura", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[187] = {187, "Shorkot", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[188] = {188, "Shujaabad", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[189] = {189, "Sialkot", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[190] = {190, "Sillanwali", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[191] = {191, "Sodhra", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[192] = {192, "Sukheke Mandi", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[193] = {193, "Surkhpur", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[194] = {194, "Talagang", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[195] = {195, "Talamba", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[196] = {196, "Tandlianwala", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[197] = {197, "Taunsa", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[198] = {198, "Toba Tek Singh", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[199] = {199, "Vihari", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[200] = {200, "Wah", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[201] = {201, "Warburton", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[202] = {202, "Wazirabad", 0, false, false, 0, INT_MAX, -1};
    cityDatabase[203] = {203, "Yazman", 0, false, false, 0, INT_MAX, -1};


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
