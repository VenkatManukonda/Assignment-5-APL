 instanceVariableNames: 'driverID name rating assignedRides'.

Driver >> initializeID: id name: n rating: r
    driverID := id.
    name := n.
    rating := r.
    assignedRides := OrderedCollection new.

Driver >> addRide: ride
    assignedRides add: ride.

Driver >> getDriverInfo
    Transcript show: 'Driver ID: ', driverID printString; cr.
    Transcript show: 'Name: ', name; cr.
    Transcript show: 'Rating: ', rating printString; cr.
    Transcript show: 'Completed Rides: ', assignedRides size printString; cr.
