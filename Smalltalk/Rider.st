 instanceVariableNames: 'riderID name requestedRides'.

Rider >> initializeID: id name: n
    riderID := id.
    name := n.
    requestedRides := OrderedCollection new.

Rider >> requestRide: ride
    requestedRides add: ride.

Rider >> viewRides
    requestedRides do: [:each |
        each rideDetails.
        Transcript show: '-------------------'; cr.
    ].
