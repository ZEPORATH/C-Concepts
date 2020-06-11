#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Contact
{
    string name;
    map<string, vector<string>*> category_contact;
    
    void operator = (const Contact & rhs)
    {
        cout << __PRETTY_FUNCTION__ << endl;    
        name = rhs.name;
        for(auto key_val: rhs.category_contact)
        {
            vector<string>* contacts = new vector<string>(key_val.second->size());
            
            //Below are ways to copy one vector to another. all are deep copy
            std::copy(key_val.second->begin(), key_val.second->end(), contacts->begin());
            // contacts->insert(contacts->begin(), key_val.second->begin(), key_val.second->end());
            // contacts->assign(key_val.second->begin(), key_val.second->end());

            category_contact[key_val.first] = contacts;
        }
    }

    ~Contact() 
    {
        cout << __PRETTY_FUNCTION__ << endl;
        for (auto& key_val: category_contact)
            if (key_val.second != nullptr)
                delete key_val.second;
    }
};

int main(int argc, char const *argv[])
{
    Contact contact1;
    contact1.name = "shashank";
    contact1.category_contact["phone"] = new vector<string>{"947538423","7021128606"};
    contact1.category_contact["Email"] = new vector<string>{"shekhar.jaigaon@gmail.com", "shashank.jaigaon@gmail.com"};
    // Contact copyContact = contact1; //This invokes copy constructor;
    Contact copyContact;
    copyContact = contact1; 
    copyContact.category_contact["phone"]->push_back ("9933802033");
    cout << "\ncopyContact " ;
    for (auto& elem: * copyContact.category_contact["phone"])
    {
        cout << elem << " " ;
    }
    cout << "\ncontact1 " ;
    
    for (auto& elem: * contact1.category_contact["phone"])
    {
        cout << elem << " " ;
    }

    cout << endl;
    int i=0;
    return 0;
}
