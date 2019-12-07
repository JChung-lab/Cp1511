//Calculate the volumen of a prism
//by Megan Wong
//Written on 21/05/2019

#include <stdio.h>

int main(void){
    int length = 0;
    int width = 0;
    int height = 0;
    printf("Please enter prism length: ");
    scanf("%d", &length);
    printf("Please enter prism width: ");
    scanf("%d", &width);
    printf("Please enter prism height: ");
    scanf("%d", &height);
    int volume = length * width * height;
    int area=(2*length*width) + (2*length*height) + (2*width*height);
    int edgeLength = 4 * length + 4 * width + 4 * height;
    printf("A prism with sides %d %d %d has:\n", length, width, height);
    printf("Volume = %d\n",volume);
    printf("Area = %d\n",area);
    printf("Edge length = %d\n",edgeLength);
    return 0;
}
