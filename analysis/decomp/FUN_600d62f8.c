// 600d62f8  FUN_600d62f8  size=188 bytes
// --- callers ---
//   600d572a FUN_600d572a
// --- callees ---
//   600d5cbe FUN_600d5cbe
//   6013d3a0 thunk_EXT_FUN_0000b572
//   60063dec FUN_60063dec
//   600d6028 FUN_600d6028
//   600d5cfc FUN_600d5cfc
//   600d410c FUN_600d410c
//   60101c52 thunk_EXT_FUN_0000b532
//   600d6256 FUN_600d6256


void FUN_600d62f8(int param_1,undefined2 param_2,ushort *param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  ushort uVar7;
  undefined2 local_34 [4];
  undefined4 local_2c;
  undefined2 local_28 [2];
  undefined1 *local_24;
  undefined1 auStack_20 [8];
  
  local_34[0] = param_2;
  iVar1 = FUN_600d6028(*(undefined4 *)(param_1 + 0x54),local_34);
  if (*(int *)(param_1 + 0x54) + 4 == iVar1) {
    return;
  }
  if (param_4 < 2) {
    return;
  }
  uVar7 = *param_3;
  uVar2 = FUN_60063dec(*(int *)(param_1 + 0x54),local_34);
  iVar1 = FUN_600d5cbe();
  if (iVar1 == 0) {
    iVar1 = FUN_600d5cfc(uVar2);
    if (iVar1 == 0) {
      uVar3 = 0;
      uVar6 = 0;
      goto LAB_600d6342;
    }
    uVar6 = 6;
  }
  else {
    uVar6 = 0xc;
  }
  uVar3 = (param_4 - 2) / uVar6 & 0xffff;
LAB_600d6342:
  if (uVar3 <= uVar7) {
    uVar7 = (ushort)uVar3;
  }
  uVar6 = (int)(short)uVar6 * (int)(short)uVar7 + 2U & 0xffff;
  puVar4 = (undefined1 *)thunk_EXT_FUN_0000b532(uVar6);
  for (puVar5 = puVar4; puVar5 != puVar4 + uVar6; puVar5 = puVar5 + 1) {
    *puVar5 = 0;
  }
  local_24 = (undefined1 *)thunk_EXT_FUN_0000b572(puVar4,param_3,uVar6);
  *local_24 = (char)uVar7;
  local_24[1] = 0;
  local_28[0] = local_34[0];
  local_2c = 0;
  FUN_600d6256(auStack_20,*(undefined4 *)(param_1 + 0x58),local_28);
  FUN_600d410c(&local_24);
  FUN_600d410c(&local_2c);
  return;
}


