// 600fc870  FUN_600fc870  size=314 bytes
// --- callers ---
//   600fc758 FUN_600fc758
//   600fc7ca FUN_600fc7ca
// --- callees ---
//   600c09f0 FUN_600c09f0


undefined1
FUN_600fc870(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            undefined1 *param_8)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 local_7c [68];
  undefined1 local_38 [16];
  undefined1 auStack_28 [18];
  undefined1 local_16;
  undefined1 local_15;
  undefined1 *local_14;
  
  local_16 = 0x41;
  local_15 = 1;
  local_14 = local_38;
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)(iVar2 + param_1);
    local_14 = puVar1;
  }
  local_14 = local_7c;
  for (iVar2 = 0; iVar2 < 7; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)(iVar2 + param_7);
    local_14 = puVar1;
  }
  for (iVar2 = 0; iVar2 < 7; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)(iVar2 + param_6);
    local_14 = puVar1;
  }
  for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)(iVar2 + param_5);
    local_14 = puVar1;
  }
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)(iVar2 + param_4);
    local_14 = puVar1;
  }
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)(iVar2 + param_3);
    local_14 = puVar1;
  }
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)(iVar2 + param_2);
    local_14 = puVar1;
  }
  iVar2 = FUN_600c09f0(local_38,local_7c,local_16,0x10,auStack_28);
  if (iVar2 == 0) {
    local_15 = 0;
  }
  local_14 = param_8;
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    *local_14 = auStack_28[iVar2];
    local_14 = local_14 + 1;
  }
  return local_15;
}


