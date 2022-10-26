#include "UserFile.h"

void UserFile::addUserToFile(User user) {
    bool fileExists = xml.Load( getFileName() );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", AuxiliaryMethod::convertIntToString(user.getId()));
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.Save(getFileName());
}

void UserFile::saveAllUsersToFile(vector <User> &users) {
    bool fileExists = xml.Load( getFileName() );

    if (fileExists) {
        xml.ResetMainPos();
        while ( xml.FindElem() )
            xml.RemoveElem();

        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    for (int i = 0; i < users.size(); i++) {
        xml.IntoElem();
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("UserId", AuxiliaryMethod::convertIntToString(users[i].getId()));
        xml.AddElem("Name", users[i].getName());
        xml.AddElem("Surname", users[i].getSurname());
        xml.AddElem("Login", users[i].getLogin());
        xml.AddElem("Password", users[i].getPassword());
        xml.OutOfElem();
        xml.OutOfElem();
    }
    xml.Save(getFileName());
}

vector <User> UserFile::loadUsersFromFile() {
    User user;
    vector <User> users;
    int id;
    string name, surname, login, pass;

    bool fileExists = xml.Load( getFileName() );

    if (fileExists) {
        xml.FindElem(); // root ORDER element
        xml.IntoElem(); // inside ORDER
        while ( xml.FindElem("User") ) {
            xml.IntoElem();
            xml.FindElem( "UserId" );
            id = AuxiliaryMethod::convertStringToInt(xml.GetData());
            xml.FindElem( "Name" );
            name = xml.GetData();
            xml.FindElem( "Surname" );
            surname = xml.GetData();
            xml.FindElem( "Login" );
            login = xml.GetData();
            xml.FindElem( "Password" );
            pass = xml.GetData();
            xml.OutOfElem();

            user.setId(id);
            user.setName(name);
            user.setSurname(surname);
            user.setLogin(login);
            user.setPassword(pass);
            users.push_back(user);
        }
    }
    return users;
}


