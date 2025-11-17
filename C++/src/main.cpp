#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Ride {
protected:
    int rideID;
    string pickupLocation;
    string dropoffLocation;
    double distance;
    double fareAmount;

public:
    Ride(int id, string pickup, string dropoff, double dist)
        : rideID(id), pickupLocation(pickup), dropoffLocation(dropoff), distance(dist), fareAmount(0) {}

    virtual double fare() {
        fareAmount = distance * 1.5;
        return fareAmount;
    }

    virtual void rideDetails() {
        cout << "Ride ID: " << rideID << endl;
        cout << "Pickup: " << pickupLocation << endl;
        cout << "Dropoff: " << dropoffLocation << endl;
        cout << "Distance: " << distance << " miles" << endl;
        cout << "Fare: $" << fare() << endl;
    }

    virtual ~Ride() {}
};

class StandardRide : public Ride {
public:
    StandardRide(int id, string pickup, string dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    double fare() override {
        fareAmount = distance * 2.0;
        return fareAmount;
    }
};

class PremiumRide : public Ride {
public:
    PremiumRide(int id, string pickup, string dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    double fare() override {
        fareAmount = distance * 3.5;
        return fareAmount;
    }
};

class Driver {
private:
    int driverID;
    string name;
    double rating;
    vector<Ride*> assignedRides;

public:
    Driver(int id, string n, double r) : driverID(id), name(n), rating(r) {}

    void addRide(Ride* ride) {
        assignedRides.push_back(ride);
    }

    void getDriverInfo() {
        cout << "Driver ID: " << driverID << endl;
        cout << "Name: " << name << endl;
        cout << "Rating: " << rating << endl;
        cout << "Completed Rides: " << assignedRides.size() << endl;
    }
};

class Rider {
private:
    int riderID;
    string name;
    vector<Ride*> requestedRides;

public:
    Rider(int id, string n) : riderID(id), name(n) {}

    void requestRide(Ride* ride) {
        requestedRides.push_back(ride);
    }

    void viewRides() {
        cout << "Ride History for " << name << ":" << endl;
        for (auto ride : requestedRides) {
            ride->rideDetails();
            cout << "------------------" << endl;
        }
    }
};

int main() {
    vector<Ride*> rides;
    rides.push_back(new StandardRide(1, "A", "B", 5));
    rides.push_back(new PremiumRide(2, "C", "D", 7));

    Driver d1(101, "John", 4.9);
    Rider r1(201, "Emma");

    for (auto r : rides) {
        d1.addRide(r);
        r1.requestRide(r);
    }

    r1.viewRides();
    d1.getDriverInfo();

    for (auto r : rides) delete r;
    return 0;
}