// #include <stdio.h>
// int main()
// {
//     char a[13];
//     int b = 0;
//     int i , cnt = 1;
//     scanf("%s", a);
//     for(i = 0; i < 11; i++){
//         if(a[i] != '-'){
//             b += (a[i] - 48) * cnt++;
//         }
//     }
//     if((a[12] - 48 == b % 11) || (b % 11 == 10 && a[12] == 'X')){
//         printf("Right");
//     }
//     else{
//         a[12] = (b % 11 == 10) ? 'X' : (b % 11) + 48;
//         printf("%s", a);
//     }
//     return 0;
// }
#include <stdio.h>//代码简洁明了（个人观点）
int main(void){
  char a[14], mod[12] = "0123456789X"; //先将mod11后的十一个字符存入数组
  gets(a); //输入字符串
  int i, j = 1, t = 0;
  for(i = 0; i < 12; i++) {
        if(a[i] == '-') continue; //字符串为分隔符‘-’时跳过此次循环进入下一次循环
    t += (a[i]-'0')*j++; //t储存 第j个  数字  * j 的和
  }
  if(mod[t%11] == a[12]) printf("Right");
  else {
      a[12] = mod[t%11]; //若识别码错误，则赋正确的识别码，然后输出
      puts(a);
  }
  return 0;
}