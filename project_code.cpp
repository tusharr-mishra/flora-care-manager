#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class plant {
protected:
    string name;
    string species;
    string sunlightreq;
    int waterfreq;
    string lastwatdate;

public:
    string type;

    plant() : name("unknown"), species("unknown"), sunlightreq("unknown"), waterfreq(0), lastwatdate("unknown"), type("plant") {}
    plant(string n, string s, string sun, int w, string l) : name(n), species(s), sunlightreq(sun), waterfreq(w), lastwatdate(l), type("plant") {}
    string getName() const { return name; }
    string getSpecies() const { return species; }
    string getSunlight() const { return sunlightreq; }
    int getWaterFreq() const { return waterfreq; }
    string getLastWaterDate() const { return lastwatdate; }
    virtual ~plant() {
        cout << "Object destroyed" << endl;
    }
    virtual void plantdet() const {
        cout << "Name: " << name << "\nSpecies: " << species
             << "\nSunlight: " << sunlightreq
             << "\nWater Frequency: " << waterfreq << " days"
             << "\nLast Watered: " << lastwatdate << endl;
    }
    virtual void updatewatersched() {
        cout << "Enter date plant was watered (DD-MM-YYYY): ";
        cin >> lastwatdate;
        cout << "Updated last watered date: " << lastwatdate << endl;
    }

    virtual void saveToFile(ofstream &file) const {
        file << type << " " << name << " " << species << " " << sunlightreq << " "
             << waterfreq << " " << lastwatdate;
    }
};
class succulent : public plant {
    string soiltype;
public:
    succulent() : plant(), soiltype("sandy") { type = "succulent"; }
    succulent(string n, string s, string sun, int w, string l, string soil)
        : plant(n, s, sun, w, l), soiltype(soil) { type = "succulent"; }

    void plantdet() const override {
        cout << "\n=== Details of Succulent ===\n";
        plant::plantdet();
        cout << "Soil Type: " << soiltype << endl;
    }

    void saveToFile(ofstream &file) const override {
        plant::saveToFile(file);
        file << " " << soiltype << endl;
    }
};
class flower : public plant {
    string color;
public:
    flower() : plant(), color("unknown") { type = "flower"; }
    flower(string n, string s, string sun, int w, string l, string c)
        : plant(n, s, sun, w, l), color(c) { type = "flower"; }

    void plantdet() const override {
        cout << "\n=== Details of Flower ===\n";
        plant::plantdet();
        cout << "Color: " << color << endl;
    }

    void saveToFile(ofstream &file) const override {
        plant::saveToFile(file);
        file << " " << color << endl;
    }
};
class cactus : public plant {
    bool spines;

public:
    cactus() : plant(), spines(true) { type = "cactus"; }
    cactus(string n, string s, string sun, int w, string l, bool spin)
        : plant(n, s, sun, w, l), spines(spin) { type = "cactus"; }

    void plantdet() const override {
        cout << "\n=== Details of Cactus ===\n";
        plant::plantdet();
        cout << "Has Spines: " << (spines ? "Yes" : "No") << endl;
    }

    void saveToFile(ofstream &file) const override {
        plant::saveToFile(file);
        file << " " << spines << endl;
    }
};
class waterplant : public plant {
    int humidityreq;
    string leafsize;
public:
    waterplant() : plant(), humidityreq(0), leafsize("unknown") { type = "waterplant"; }
    waterplant(string n, string s, string sun, int w, string l, int h, string leaf)
        : plant(n, s, sun, w, l), humidityreq(h), leafsize(leaf) { type = "waterplant"; }

    void plantdet() const override {
        cout << "\n=== Details of Water Plant ===\n";
        plant::plantdet();
        cout << "Humidity Requirement: " << humidityreq << "%"
             << "\nLeaf Size: " << leafsize << endl;
    }

    void saveToFile(ofstream &file) const override {
        plant::saveToFile(file);
        file << " " << humidityreq << " " << leafsize << endl;
    }
};
plant *plants[100];
int plantcount = 0;

void addplant();
void viewallplants();
void wateringplant();
void saveplants();
void displayfile();
void displaymenu();
void displaymenu() {
    int choice = 0;
    do {
        cout << "\n========================================\n";
        cout << "   FLORA CARE MANAGER - MAIN MENU\n";
        cout << "========================================\n";
        cout << "1. Add new plant\n";
        cout << "2. View all plants\n";
        cout << "3. Water a plant\n";
        cout << "4. Exit\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 
        switch (choice) {
            case 1: 
                addplant(); 
                saveplants(); 
                break;
            case 2: 
                viewallplants(); 
                break;
            case 3: 
                wateringplant(); 
                saveplants(); 
                break;
            case 4: 
                cout << "\nExiting Flora Care Manager. Goodbye!\n";
                break;
            default: 
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 4);
}
void addplant() {
    if (plantcount >= 100) {
        cout << "\nCan't add more plants! Maximum capacity reached.\n";
        return;
    }

    string name, species, sunlightreq, lastwaterdate;
    int waterfreq, choice;

    cout << "\n--- Select Plant Type ---\n";
    cout << "1. Succulent\n";
    cout << "2. Flower\n";
    cout << "3. Cactus\n";
    cout << "4. Water Plant\n";
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore(); 

    cout << "\nEnter plant name: "; 
    getline(cin, name);
    cout << "Enter species: "; 
    getline(cin, species);
    cout << "Enter sunlight requirement (e.g., Full/Partial/Shade): "; 
    getline(cin, sunlightreq);
    cout << "Enter water frequency (in days): "; 
    cin >> waterfreq;
    cin.ignore();
    cout << "Enter last water date (DD-MM-YYYY): "; 
    getline(cin, lastwaterdate);

    if (choice == 1) {
        string soiltype;
        cout << "Enter soil type (e.g., Sandy/Loamy/Clay): "; 
        getline(cin, soiltype);
        plants[plantcount++] = new succulent(name, species, sunlightreq, waterfreq, lastwaterdate, soiltype);
        cout << "\nSucculent added successfully!\n";
    } else if (choice == 2) {
        string color;
        cout << "Enter flower color: "; 
        getline(cin, color);
        plants[plantcount++] = new flower(name, species, sunlightreq, waterfreq, lastwaterdate, color);
        cout << "\nFlower added successfully!\n";
    } else if (choice == 3) {
        string spineInput;
        cout << "Has spines? (yes/no): "; 
        getline(cin, spineInput);
        bool spike = (spineInput == "yes" || spineInput == "Yes" || spineInput == "YES" || spineInput == "true" || spineInput == "1");
        plants[plantcount++] = new cactus(name, species, sunlightreq, waterfreq, lastwaterdate, spike);
        cout << "\nCactus added successfully!\n";
    } else if (choice == 4) {
        int humid; 
        string leafsize;
        cout << "Enter humidity requirement (%): "; 
        cin >> humid;
        cin.ignore();
        cout << "Enter leaf size (Small/Medium/Large): "; 
        getline(cin, leafsize);
        plants[plantcount++] = new waterplant(name, species, sunlightreq, waterfreq, lastwaterdate, humid, leafsize);
        cout << "\nWater plant added successfully!\n";
    } else {
        cout << "\nInvalid choice! Plant not added.\n";
    }
}

void viewallplants() {
    if (plantcount == 0) {
        cout << "\nNo plants available in the system.\n";
        return;
    }
    
    cout << "\n========================================\n";
    cout << "   ALL PLANTS IN THE SYSTEM\n";
    cout << "========================================\n";
    
    for (int i = 0; i < plantcount; i++) {
        cout << "\n--- Plant #" << i + 1 << " ---";
        plants[i]->plantdet();
        cout << "----------------------------------------\n";
    }
}

void wateringplant() {
    if (plantcount == 0) {
        cout << "\nNo plants to water.\n";
        return;
    }
    
    cout << "\n--- Water a Plant ---\n";
    cout << "Total plants: " << plantcount << endl;
    int num;
    cout << "Enter the plant number to water (1-" << plantcount << "): ";
    cin >> num;
    cin.ignore(); // Clear buffer
    
    if (num <= 0 || num > plantcount) {
        cout << "\nInvalid plant number!\n";
    } else {
        plants[num - 1]->updatewatersched();
        cout << "\nPlant watered successfully!\n";
    }
}

void saveplants() {
    ofstream file("plants.txt");
    if (!file) {
        cout << "\nError opening file for saving!\n";
        return;
    }
    
    for (int i = 0; i < plantcount; i++) {
        plants[i]->saveToFile(file);
    }
    
    file.close();
    cout << "Data saved to file successfully.\n";
}

void displayfile() {
    ifstream file("plants.txt");
    if (!file) {
        cout << "No existing plant data found. Starting fresh.\n";
        return;
    }
    string type;
    while (file >> type) {
        string name, species, sunlight, lastwater;
        int waterfreq;
        if (type == "succulent") {
            string soil;
            file >> name >> species >> sunlight >> waterfreq >> lastwater >> soil;
            plants[plantcount++] = new succulent(name, species, sunlight, waterfreq, lastwater, soil);
        } else if (type == "flower") {
            string color;
            file >> name >> species >> sunlight >> waterfreq >> lastwater >> color;
            plants[plantcount++] = new flower(name, species, sunlight, waterfreq, lastwater, color);
        } else if (type == "cactus") {
            bool spines;
            file >> name >> species >> sunlight >> waterfreq >> lastwater >> spines;
            plants[plantcount++] = new cactus(name, species, sunlight, waterfreq, lastwater, spines);
        } else if (type == "waterplant") {
            int humid;
            string leaf;
            file >> name >> species >> sunlight >> waterfreq >> lastwater >> humid >> leaf;
            plants[plantcount++] = new waterplant(name, species, sunlight, waterfreq, lastwater, humid, leaf);
        }
    }
    
    file.close();
    if (plantcount > 0) {
        cout << "Loaded " << plantcount << " plant(s) from file.\n";
    }
}

int main() {
    cout << "========================================\n";
    cout << "  WELCOME TO FLORA CARE MANAGER\n";
    cout << "========================================\n\n";
    
    // Create file if it doesn't exist
    ofstream createFile("plants.txt", ios::app);
    createFile.close();
    
    // Load existing plants from file
    displayfile();
    
    // Display main menu
    displaymenu();
    for (int i = 0; i < plantcount; i++) {
        delete plants[i];
    }
    
    cout << "\nAll resources cleaned up. Thank you for using Flora Care Manager!\n";
    
    return 0;
}