void loop(double c[], double a[], double b[], int n)
{
     register int i asm("%eax");

     for (i=0;i<n;i++)
       c[i] = a[i] + b[i];
}
