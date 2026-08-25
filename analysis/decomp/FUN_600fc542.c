// 600fc542  FUN_600fc542  size=192 bytes
// --- callers ---
//   600c10a4 FUN_600c10a4
//   600c1158 FUN_600c1158
//   600c11bc FUN_600c11bc
// --- callees ---
//   600c09f0 FUN_600c09f0


void FUN_600fc542(int param_1,int param_2,int param_3,undefined1 param_4,undefined1 *param_5)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 auStack_78 [32];
  undefined1 local_58;
  undefined1 local_57 [66];
  undefined1 local_15;
  undefined1 *local_14;
  
  local_15 = 0x41;
  local_14 = local_57;
  for (iVar2 = 0; iVar2 < 0x20; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)(iVar2 + param_2);
    local_14 = puVar1;
  }
  for (iVar2 = 0; iVar2 < 0x20; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)(iVar2 + param_1);
    local_14 = puVar1;
  }
  local_14 = auStack_78 + 0x10;
  local_58 = param_4;
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)(iVar2 + param_3);
    local_14 = puVar1;
  }
  FUN_600c09f0(auStack_78 + 0x10,&local_58,local_15,0x10,auStack_78);
  local_14 = param_5;
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    *local_14 = auStack_78[iVar2];
    local_14 = local_14 + 1;
  }
  return;
}


