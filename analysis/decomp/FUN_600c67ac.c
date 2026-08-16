// 600c67ac  FUN_600c67ac  size=330 bytes
// --- callers ---
//   600feba8 FUN_600feba8
// --- callees ---
//   60094fac FUN_60094fac
//   600ef648 FUN_600ef648
//   600ef2da FUN_600ef2da
//   60094d24 FUN_60094d24
//   600f3b78 FUN_600f3b78


undefined1
FUN_600c67ac(undefined2 param_1,int *param_2,int param_3,int param_4,int param_5,undefined2 param_6)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int local_50;
  undefined2 local_3c [2];
  undefined2 local_38;
  undefined2 local_28 [2];
  undefined2 local_24;
  byte local_12;
  undefined1 local_11;
  
  local_11 = 0;
  local_28[0] = 2;
  local_24 = 0x1801;
  local_3c[0] = 2;
  local_38 = 0x2a05;
  iVar2 = FUN_600ef2da(param_5 + 8,local_28,1);
  if ((iVar2 != 0) && (iVar2 = FUN_600ef2da(param_5 + 0x24,local_3c,1), iVar2 != 0)) {
    local_11 = 1;
    *(undefined1 *)(param_3 + 0x31) = 1;
    FUN_600ef648(param_1);
    *(char *)(param_3 + 0x26) = *(char *)(param_3 + 0x26) + '\x01';
    bVar1 = *(byte *)(param_3 + 0x26);
    uVar3 = FUN_60094fac();
    if (bVar1 == uVar3) {
      local_50 = param_4;
      if ((param_4 == 0) || ((param_4 != 0 && (*(int *)(param_4 + 0x14) != 0)))) {
        for (local_12 = 0; local_12 < 6; local_12 = local_12 + 1) {
          if (((*(char *)((uint)local_12 * 0x20 + DAT_600c68f8 + 0x4ab) != '\0') &&
              (param_3 == *(int *)((local_12 + 0x25) * 0x20 + DAT_600c68f8))) &&
             (*(int *)((local_12 + 0x25) * 0x20 + DAT_600c68f8 + 4) == 0)) {
            local_50 = (uint)local_12 * 0x20 + 0x490 + DAT_600c68f8;
            break;
          }
        }
      }
      FUN_600f3b78(param_1,param_6);
      if (local_50 != 0) {
        FUN_60094d24(local_50,0x1d0e,0);
      }
    }
    if (*param_2 != 0) {
      (*(code *)*param_2)(0xf,param_3 + 1);
    }
  }
  return local_11;
}


