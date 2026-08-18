// 600cfc8e  FUN_600cfc8e  size=164 bytes
// --- callers ---
//   600d0590 FUN_600d0590
//   600d0332 FUN_600d0332
// --- callees ---
//   600cfc34 FUN_600cfc34
//   600cfc52 FUN_600cfc52
//   600d10f6 FUN_600d10f6
//   600cfc70 FUN_600cfc70


undefined4 FUN_600cfc8e(undefined4 *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int *piStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  if (*param_2 == 0) {
    uVar5 = 1;
  }
  else {
    iVar4 = 0;
    uVar5 = 1;
    puVar6 = param_1;
    piStack_24 = param_2;
    local_20 = param_3;
    uStack_1c = param_4;
    while( true ) {
      uVar1 = (uint)*(byte *)(*param_2 + 4);
      if ((int)uVar1 <= iVar4) break;
      iVar3 = *(int *)(*param_2 + 8);
      iVar2 = iVar4 * 4;
      iVar4 = iVar4 + 1;
      uVar5 = FUN_600d10f6(*param_1,*(undefined1 *)(iVar3 + iVar2),uVar1,iVar3,puVar6);
    }
    for (iVar4 = 0; iVar4 < (int)(uint)*(byte *)(*param_2 + 4); iVar4 = iVar4 + 1) {
      iVar2 = *(int *)(*param_2 + 8);
      if ((*(byte *)(iVar2 + iVar4 * 4 + 1) & 0x30) == 0x10) {
        if (*(char *)((int)param_1 + 0x1d) != '\0') {
          local_20 = 0xffffffff;
          FUN_600cfc52(*param_1,&piStack_24,param_1);
        }
      }
      else if (*(char *)(iVar2 + iVar4 * 4) < '\0') {
        if (*(char *)((int)param_1 + 0x1b) != '\0') {
          local_20 = 0xffffffff;
          FUN_600cfc34(*param_1,&piStack_24,param_1);
        }
      }
      else if (*(char *)(param_1 + 7) != '\0') {
        local_20 = 0xffffffff;
        FUN_600cfc70(*param_1,&piStack_24,param_1);
      }
    }
    *param_2 = 0;
  }
  return uVar5;
}


