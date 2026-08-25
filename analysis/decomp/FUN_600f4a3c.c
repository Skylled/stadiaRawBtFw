// 600f4a3c  FUN_600f4a3c  size=338 bytes
// --- callers ---
//   600acf50 FUN_600acf50
// --- callees ---
//   600ac6ac FUN_600ac6ac
//   600f46b4 FUN_600f46b4
//   600b00b4 FUN_600b00b4


void FUN_600f4a3c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,char *param_5
                 )

{
  char cVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_2 + 0xc);
  cVar1 = *param_5;
  sVar3 = (ushort)(byte)param_5[2] * 0x100 + (ushort)(byte)param_5[1];
  cVar2 = param_5[3];
  if (*(char *)(param_2 + 0x31) == '\x01') {
    FUN_600ac6ac(param_1,param_2,cVar1,sVar3,cVar2);
  }
  else if ((((*(char *)(param_2 + 0x31) == '\x03') && (*(char *)(param_2 + 0x32) == '\x02')) &&
           (iVar4 != 0)) && (sVar3 == *(short *)(iVar4 + 2))) {
    if (cVar1 == '\x16') {
      if (*(char *)(param_2 + 0x33) == '\0') {
        *(char *)(param_2 + 0x33) = cVar2;
      }
      if (*(short *)(iVar4 + 4) == 0) {
        FUN_600b00b4(param_2,*(undefined1 *)(param_2 + 0x33),0);
      }
      else {
        FUN_600f46b4(param_1,param_2,0);
      }
    }
    else {
      if (*(char *)(param_2 + 0x33) == '\0') {
        *(char *)(param_2 + 0x33) = cVar2;
      }
      FUN_600b00b4(param_2,*(undefined1 *)(param_2 + 0x33),0);
    }
  }
  else if ((((*(char *)(param_2 + 0x31) == '\x02') &&
            ((*(char *)(param_2 + 0x32) == -0x7c || (*(char *)(param_2 + 0x32) == '\x02')))) &&
           (cVar1 == '\f')) && ((*(char *)(param_2 + 0x34) != '\0' && (cVar2 == '\v')))) {
    FUN_600b00b4(param_2,0,*(undefined4 *)(param_2 + 0xc));
  }
  else {
    FUN_600b00b4(param_2,cVar2,0);
  }
  return;
}


