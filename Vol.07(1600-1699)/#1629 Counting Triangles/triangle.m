% Step 为三角形的边长
Step = 10;

x = [0  0
     10 0];

for t = Step-1 : -1 : 0;
    
    xlast = 5.5 + t/2;
    ylast = 0 + sqrt(3)/2 * (9 - t);
    
    for k = 0 : t
        
        xlast = xlast - .5;
        ylast = ylast + sqrt(3)/2;
        x = [x; xlast ylast];
        xlast = xlast - .5;
        ylast = ylast - sqrt(3)/2;
        x = [x; xlast ylast];
       
    end
    
    xlast = xlast + .5;
    ylast = ylast + sqrt(3)/2;
    
    x = [x; xlast,ylast];
    xlast = xlast + t;
    x = [x; xlast,ylast];

end

plot( x(:,1), x(:,2), 'k' )

hold on

axis( [-1, Step+1, -1, Step-1] )