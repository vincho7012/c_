#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[]) {

  int a, b, c, d;
  float x1, x2, im, re;
  scanf("%d %d %d",&a,&b,&c);

  if(a == 0 && b == 0){
    printf("Izrodeno uravnenie\n");
  }
  else {
    if(a == 0) {
      printf("Linejno uravnenie: x = %.2f\n", (float)-c/b);
    }
    else {
      if(c == 0) {
        printf("x1 = %.2f, x2 = 0\n", (float)-b/a);
      }
      else {
        d = b * b - 4*a*c;
        if(d > 0) {
          x1 = (-b + sqrt(d))/(2*a);
          x2 = (-b - sqrt(d))/(2*a);
          printf("x1 = %.2f, x2 = %.2f\n", x1, x2 );
        }
        else if(d < 0) {
          re = -b/(2*a);
          im = sqrt(-1*d)/(2*a);
          if(im < 0) im*=-1;
          printf("Z1 = %.2f + %.2fi\nZ2 = %.2f - %.2fi\n",re,im,re,im);
        }
        else {
        x1 = -b/(2*a);
        printf("x1 = x2 =  %.2f\n", x1);
        }
      }
    }
  }
}
