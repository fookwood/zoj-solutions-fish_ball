import java.util.*;
import java.io.*;


class triangulate_mg 
{
    static BufferedReader stdin;
    static final int infty = 1<<30;
    
    int[] x, y;
    int npts;
    boolean[][] legal;
    
    public static void main(String[] ss)  throws IOException
    {
	Reader rdr = new InputStreamReader(System.in);
	stdin = new BufferedReader(rdr);	
	int n = Integer.parseInt(stdin.readLine());
	for (int i = 1; i <= n; ++i)
	    (new triangulate_mg()).solve(i);
    }
    

    int signedarea(int i, int j, int k) 
    {
	return (x[j]-x[k])*(y[j]-y[i]) - (x[j]-x[i])*(y[j]-y[k]);
    }

    long dist2(int i, int j)
    {
	long dx = x[i]-x[j];
	long dy = y[i]-y[j];
	return dx*dx + dy*dy;
    }
    
    boolean between(int i, int j, int k)
    {
	if (signedarea(i, j, k) != 0) return false;
	return (dist2(i,k) < dist2(i,j) && dist2(j,k) < dist2(i,j));	
    }

    boolean intersect(int i, int j, int r, int s) 
    {
	long a1 = signedarea(i, j, r);
	long a2 = signedarea(i, j, s);
	long a3 = signedarea(r, s, i);
	long a4 = signedarea(r, s, j);
	return a1*a2 < 0 && a3*a4 < 0;	
    }
    
    
    boolean checklegal(int i, int j) 
    {
	if ( j < i) return checklegal(j, i);
	if (i==j) return false;
	if (j == i+1) return true;
	if (i==0 && j==npts-1) return true;	
	// The line i to j cannot intersect the polygon
	// except att points i and j.
	for (int k = 0; k < npts; ++k) 
	    if (k != i && k != j && between(i,j,k))
		return false;	    
	// the line cannot intersect the polygon
	if (intersect(i,j, 0, npts-1)) return false;
	for (int k = 0; k+1 < npts; ++k) 
	    if (intersect(i, j, k, k+1)) return false;
	return true;	
    }
    

    void solve(int cnt) throws IOException
    {
	//	System.err.println("Case " + cnt);
	
	npts = Integer.parseInt(stdin.readLine());
	x = new int[npts];
	y = new int[npts];
	String[] pts;
	for (int i = 0; i < npts; ++i) {
	    pts = stdin.readLine().split(" ");
	    x[i] = Integer.parseInt(pts[0]);
	    y[i] = Integer.parseInt(pts[1]);
	}
	
	int acheck=0;
	for (int i = 1; i+1 < npts; ++i) acheck += signedarea(0,i,i+1);

	if (acheck < 0) {
	    // System.err.println("reversing case " + cnt);
	    int i,j, tmp;
	    for (i=0, j =npts-1; i<j; ++i, --j) {
		tmp = x[i]; x[i] = x[j]; x[j] = tmp;
		tmp = y[i]; y[i] = y[j]; y[j] = tmp;
	    }
	    
	}
	
	
	legal = new boolean[npts][npts];
	for (int i = 0; i < npts; ++i) 
	    for (int j = i; j < npts; ++j) 
		legal[j][i] = legal[i][j] = checklegal(i, j);		
	
	int[][] area = new int[npts][npts];
	for (int i=0; i < npts; ++i) {	    
	    area[i][i] = 0;
	    if (i+1 < npts) area[i][i+1] = 0;
	    if (i+2 < npts) {
		area[i][i+2] = signedarea(i,i+1,i+2);
		if (area[i][i+2] < 0) area[i][i+2] = infty;
	    }
	    
	}
	
	for (int k=3; k < npts; ++k)
	    for (int i = 0; i+k < npts; ++i) {
		int j = i+k;
		area[i][j] = infty;
		for (int r = i+1; r < j; ++r) {
		    if (legal[i][r] && legal[j][r]) {
			int a = signedarea(i, r, j);
			if (a > 0) {
			    a = Math.max(a, area[i][r]);
			    a = Math.max(a, area[r][j]);
			    if (a < area[i][j]) area[i][j] = a;
			}
		    }
		}
		
	    }
	int intpart = area[0][npts-1]/2;
	int fracpart = 5*(area[0][npts-1]%2);
	System.out.println(intpart + "." + fracpart);	
	
       	
    }
}

	
    
