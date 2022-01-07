#include <iostream>
using namespace std;
class Event
{
protected:
    string name;
    string detail;
    string type;
    string organiser;

public:
    Event()
    {
        // name = "Wedding";
        // detail = "Wedding Ceremony Event";
        // type = "Big Event";
        // organiser = "HarshG";
    }

    Event(string myname, string mydetail, string mytype, string myorganiser)
    {
        name.assign(myname);
        // this.name = name;
        detail.assign(mydetail);
        type.assign(type);
        organiser.assign(organiser);
    }
    string get_name()
    {
        return name;
    }
    string get_detail()
    {
        return detail;
    }
    string get_type()
    {
        return type;
    }
    string get_organiser()
    {
        return organiser;
    }
    void set_name(string myname)
    {
        name.assign(myname);
    }
    void set_detail(string mydetail)
    {
        detail.assign(mydetail);
    }
    void set_type(string mytype)
    {
        type.assign(mytype);
    }
    void set_organiser(string myorganiser)
    {
        organiser.assign(myorganiser);
    }
};

class Exhibition : public Event
{
private:
    int numberofStalls;

public:
    int get_numberofStalls()
    {
        return numberofStalls;
    }
    void set_numberofStalls(int n)
    {
        numberofStalls = n;
    }
    Exhibition(string name, string detail, string type, string organiser, int mynumberofStalls) : Event(name, detail, type, organiser)
    {
        // super(name, detail, type, organiser);
        numberofStalls = numberofStalls;
    }

    void display()
    {
        cout << "\tEvent details" << endl;
        cout << "Name : " << get_name() << endl;
        cout << "detail : " << get_detail() << endl;
        cout << "type : " << get_type() << endl;
        cout << "organiser : " << get_organiser() << endl;
        cout << "Number of Stalls : " << get_numberofStalls() << endl;
    }
};
class StageEvent : public Event
{
    int numberofSeats;

public:
    StageEvent()
    {
    }
    StageEvent(string name, string detail, string type, string organiser, int mynumberofSeats) : Event(name, detail, type, organiser)
    {
        // super(name, detail, type, organiser, "");
        numberofSeats = mynumberofSeats;
    }

    int get_numberofSeats()
    {
        return numberofSeats;
    }
    void set_numberofSeats(int n)
    {
        numberofSeats = n;
    }
    void display()
    {
        cout << "\tStage Event details" << endl;
        cout << "Name : " << get_name() << endl;
        cout << "detail : " << get_detail() << endl;
        cout << "type : " << get_type() << endl;
        cout << "organiser : " << get_organiser() << endl;
        // cout << "Number of Stalls : " << get_numberofStalls() << endl;
        cout << "Number of Seats : " << get_numberofSeats() << endl;
    }
};
int main()
{
    // Exhibition exb("Wedding","Wedding function ","Big Event","HarshG",50);
    // exb.display();
    // // Event ev;
    // // ev.get_detail();
    int choice;
    string name;
    string detail;
    string type;
    string organiser;
    int stalls;
    int seats;
    cout << "Choose Event" << endl;
    cout << "1) Exhibition \n2)Stage Event" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:

        Exhibition exb();
        // cout << "Enter the details in csv format" << endl;
        // cin >> name;
        // cin >> detail;
        // cin >> type;
        // cin >> organiser;
        // cin >> stalls;
        exb.set_name("Book Expo");
        exb.set_detail("Special Sale");
        exb.set_type("Academics");
        exb.set_organiser("John");
        exb.set_numberofStalls(12);
        exb.display();
        break;
    case 2:

        StageEvent st();
        // cout << "Enter the details in csv format" << endl;
        // cin >> name;
        // cin >> detail;
        // cin >> type;
        // cin >> organiser;
        // cin >> seats;
        st.set_name("Magical Show");
        st.set_detail("New Year Special");
        st.set_type("Magic");
        st.set_organiser("Robert");
        st.set_numberofSeats(55);
        st.display();
        break;

    default:
        cout << "Invalid Choice" << endl;
        break;
    }
    return 0;
}