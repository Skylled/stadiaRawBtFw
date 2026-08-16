// 600c12b0  FUN_600c12b0  size=300 bytes
// --- callers ---
//   600c1204 FUN_600c1204
// --- callees ---
//   600c09f0 FUN_600c09f0


uint FUN_600c12b0(int param_1,int param_2,int param_3,int param_4)

{
  undefined1 *puVar1;
  int iVar2;
  byte local_8c;
  byte local_8b;
  byte local_8a;
  byte local_89;
  undefined1 local_7c [16];
  undefined1 local_6c [83];
  undefined1 local_19;
  uint local_18;
  undefined1 *local_14;
  
  local_19 = 0x50;
  local_14 = local_6c;
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)(iVar2 + param_4);
    local_14 = puVar1;
  }
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
  local_14 = local_7c;
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    puVar1 = local_14 + 1;
    *local_14 = *(undefined1 *)(iVar2 + param_3);
    local_14 = puVar1;
  }
  iVar2 = FUN_600c09f0(local_7c,local_6c,local_19,0x10,&local_8c);
  local_18 = DAT_600c13dc;
  if (iVar2 != 0) {
    for (local_18 = (uint)local_89 * 0x1000000 +
                    (uint)local_8c + (uint)local_8b * 0x100 + (uint)local_8a * 0x10000;
        DAT_600c13e4 < local_18; local_18 = DAT_600c13e0 + local_18) {
    }
  }
  return local_18;
}


