#include<bits/stdc++.h>

using namespace std;

struct Workshops {
    int startTime;
    int duration;
    int endTime;
    Workshops(int startTime, int duration): startTime(startTime), duration(duration) {
        endTime = startTime+duration;
    }
};

struct Available_Workshops{
    int n;
    std::vector<Workshops> workShops {};
};

Available_Workshops* initialize (int start_time[], int duration[], int n)
{
    Available_Workshops* avWorkshop = new Available_Workshops();
    for(int i=0; i< n; i++)
    {
        Workshops workShop(start_time[i], duration[i]);
        avWorkshop->workShops.push_back(workShop);
    }
    return avWorkshop;
}


int CalculateMaxWorkshops(Available_Workshops* ptr) 
{
    auto workshops = ptr->workShops;
    sort(workshops.begin(), workshops.end(), [](const Workshops& a, const Workshops& b){
        return b.endTime > a.endTime;
    });
    int f = 0, res = 0;
    for (auto a: workshops)
    {
        if (a.startTime >= f)
        {
            res++;
            f = a.endTime;
        }
    }
    return res;
}
//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
