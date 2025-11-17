 instanceVariableNames: 'rideID pickupLocation dropoffLocation distance fareAmount'.

Ride >> initializeID: id pickup: pickup dropoff: drop distance: dist
    rideID := id.
    pickupLocation := pickup.
    dropoffLocation := drop.
    distance := dist.
    fareAmount := 0.

Ride >> fare
    fareAmount := distance * 1.5.
    ^ fareAmount.

Ride >> rideDetails
    Transcript show: 'Ride ID: ', rideID printString; cr.
    Transcript show: 'Pickup: ', pickupLocation; cr.
    Transcript show: 'Dropoff: ', dropoffLocation; cr.
    Transcript show: 'Distance: ', distance printString; cr.
    Transcript show: 'Fare: ', self fare printString; cr.

Ride subclass: #StandardRide
    instanceVariableNames: ''.

StandardRide >> fare
    fareAmount := distance * 2.
    ^ fareAmount.
