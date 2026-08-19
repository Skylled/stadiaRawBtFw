// 600dfd24  FUN_600dfd24  size=70 bytes
// --- callers ---
//   600d4664 FUN_600d4664
// --- callees ---
//   600dfcf2 FUN_600dfcf2


char FUN_600dfd24(int *param_1,int param_2,int *param_3,undefined1 *param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_1c;
  int *piStack_18;
  
  if ((param_2 == 0) || (param_3 == (int *)0x0)) {
    cVar1 = '\x03';
  }
  else {
    local_1c = 0;
    piStack_18 = param_3;
    cVar1 = FUN_600dfcf2(param_1,param_2,&local_1c,0,param_1);
    if (cVar1 == '\0') {
      iVar4 = param_1[2];
      iVar3 = *param_1;
      iVar2 = iVar4 + local_1c * 0x10;
      iVar5 = *(int *)(iVar2 + 4);
      *param_3 = *(int *)(iVar2 + 8) - iVar5;
      param_3[1] = iVar3 + iVar5;
      if (param_4 != (undefined1 *)0x0) {
        *param_4 = *(undefined1 *)(iVar4 + local_1c * 0x10);
      }
      cVar1 = '\0';
    }
  }
  return cVar1;
}


