// 600fc602  FUN_600fc602  size=342 bytes
// --- callers ---
//   600c13e8 FUN_600c13e8
// --- callees ---
//   600c09f0 FUN_600c09f0


undefined1
FUN_600fc602(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,undefined1 *param_9)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 local_70 [56];
  undefined1 local_38 [16];
  undefined1 auStack_28 [18];
  undefined1 local_16;
  undefined1 local_15;
  undefined1 *local_14;
  
  local_16 = 0x35;
  local_15 = 1;
  local_14 = local_38;
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)(iVar2 + param_1);
    local_14 = puVar1;
  }
  local_14 = local_70;
  for (iVar2 = 0; iVar2 < 2; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)(iVar2 + param_8);
    local_14 = puVar1;
  }
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
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)(iVar2 + param_5);
    local_14 = puVar1;
  }
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)(iVar2 + param_4);
    local_14 = puVar1;
  }
  for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)(iVar2 + param_3);
    local_14 = puVar1;
  }
  for (iVar2 = 0; iVar2 < 1; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)(iVar2 + param_2);
    local_14 = puVar1;
  }
  iVar2 = FUN_600c09f0(local_38,local_70,local_16,0x10,auStack_28);
  if (iVar2 == 0) {
    local_15 = 0;
  }
  local_14 = param_9;
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    *local_14 = auStack_28[iVar2];
    local_14 = local_14 + 1;
  }
  return local_15;
}


