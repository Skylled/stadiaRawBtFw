// 600cf7b6  FUN_600cf7b6  size=94 bytes
// --- callers ---
// --- callees ---
//   600ced08 FUN_600ced08


void FUN_600cf7b6(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int extraout_r1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_2[1];
  iVar2 = (uint)*(byte *)(iVar3 + 0xe5) * 8 + 0xb4;
  iVar1 = iVar3 + iVar2;
  *(undefined4 *)(iVar3 + iVar2) = 0;
  *(undefined4 *)(iVar1 + 4) = 0;
  *(byte *)(iVar3 + 0xe5) = *(char *)(iVar3 + 0xe5) + 1U & 3;
  if (*(code **)(iVar3 + 0xc) != (code *)0x0) {
    (**(code **)(iVar3 + 0xc))(*param_2,iVar3,0x771,*(undefined4 *)(iVar3 + 0x10));
    iVar1 = extraout_r1;
  }
  if (*(int *)(iVar3 + (uint)*(byte *)(iVar3 + 0xe5) * 8 + 0xb4) == 0) {
    iVar2 = *param_2;
    *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) & 0xffe3fffe;
    FUN_600ced08(param_1,iVar1,iVar2,param_4);
    return;
  }
  return;
}


