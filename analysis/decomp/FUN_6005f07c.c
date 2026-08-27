// 6005f07c  FUN_6005f07c  size=144 bytes
// --- callers ---
//   60067e44 FUN_60067e44
// --- callees ---
//   6005ee88 bee__6005ee88
//   6005ef04 bee__6005ef04
//   60052364 FUN_60052364
//   6005ee58 FUN_6005ee58


uint FUN_6005f07c(int *param_1,undefined4 param_2,undefined4 param_3)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_6005f10c;
  if ((*DAT_6005f10c & 1) == 0) {
    FUN_60052364(DAT_6005f10c);
    uVar2 = bee__6005ef04(param_1,0,param_2);
    if ((uVar2 & 0xff) == 0) {
      uVar2 = bee__6005ef04(param_1 + 5,1,param_3);
      if ((uVar2 & 0xff) == 0) {
        *puVar1 = *puVar1 | 0x11;
        FUN_6005ee58(param_1);
        FUN_6005ee58(param_1 + 5);
        uVar2 = 0;
      }
    }
  }
  else if ((((char)param_1[4] == '\0') ||
           (uVar2 = bee__6005ee88(*param_1,param_1[1] + *param_1 + -1,0), (uVar2 & 0xff) == 0)) &&
          (((char)param_1[9] == '\0' ||
           (uVar2 = bee__6005ee88(param_1[5],param_1[6] + param_1[5] + -1,1), (uVar2 & 0xff) == 0)))
          ) {
    uVar2 = 0;
  }
  return uVar2;
}


