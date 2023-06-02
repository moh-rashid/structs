
weather(sunday,fair).
weather(monday,overcast).
weather(tuseday,fair).
weather(wednsday,fair).
weather(thursday,overcast).
weather(friday,rainy).
weather(sateday,overcast).

birdsActive(sunday).
birdsActive(tuesday).
birdsActive(thursday).

color(sky,blue,Day) :- weather(Day,fair).
color(sky,grey,Day) :- weather(Day,overcast).
birdsHappy(Day) :- birdsActive(Day), weather(Day,fair).
