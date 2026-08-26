// 600d7f60  FUN_600d7f60  size=126 bytes
// --- callers ---
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


uint FUN_600d7f60(int *param_1,int param_2,uint param_3)

{
  char *pcVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  uVar7 = 0;
  do {
    if (param_3 <= uVar7) {
      return 0;
    }
    iVar6 = 0;
    iVar4 = 0x60 - param_1[0x1b];
    iVar5 = param_3 - uVar7;
    if (iVar4 <= (int)(param_3 - uVar7)) {
      iVar5 = iVar4;
    }
    do {
      if (iVar5 <= iVar6) {
        bVar2 = false;
        goto LAB_600d7fa2;
      }
      pcVar1 = (char *)(param_2 + uVar7 + iVar6);
      iVar6 = iVar6 + 1;
    } while (*pcVar1 != '\n');
    bVar2 = true;
    iVar5 = iVar6;
LAB_600d7fa2:
    thunk_EXT_FUN_0000b572((int)param_1 + param_1[0x1b] + 0xc,param_2 + uVar7,iVar5);
    iVar4 = param_1[0x1b];
    uVar7 = uVar7 + iVar5;
    param_1[0x1b] = iVar5 + iVar4;
    if (((bVar2) || (0x5f < (uint)(iVar5 + iVar4))) &&
       (uVar3 = (**(code **)(*param_1 + 0x14))(param_1), (uVar3 & 0xff) != 0)) {
      return uVar3;
    }
  } while( true );
}


