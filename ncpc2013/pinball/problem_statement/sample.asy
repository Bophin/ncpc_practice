transform sc = scale(20);
draw(sc * ((-1,1)--(1,-1)), black*1.5 + 0.8);
draw(sc * ((1,-2)--(2,-3)), black*1.5 + 0.8);
currentpicture=shift(0,-1.5)*currentpicture;
draw((0,2)*20--(0,0)*20--(1,-1)*20--(1,-2)*20--(2,-3)*20--(2,-4)*20,red+opacity(.5)+1.7);
