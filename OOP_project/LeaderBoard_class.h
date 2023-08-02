#pragma once

class LeaderBoard
{
public:
    LeaderBoard() = default;



    void Top10(Data_Base* database);
};



void LeaderBoard::Top10(Data_Base* database)
{
    vector<User*> users;
    for (size_t i = 0; i < database->users_count; i++)
    {
        users.push_back(database->users[i]);
    }



    sort(begin(users), end(users), [](User* u1, User* u2) -> bool
        {
            return u1->get_total() > u2->get_total();
        });



    size_t count = min(users.size(), static_cast<size_t>(10));



    cout << "Top 10 Users:" << endl;
    for (size_t i = 0; i < count; i++)
    {
        cout << i + 1 << ". " << users[i]->getName() << " - Total Points: " << users[i]->get_total() << endl;
    }
}