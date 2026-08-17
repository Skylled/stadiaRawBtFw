// 600cb210  key_value_store__600cb210  size=88 bytes
// src: key_value_store.h
// --- callers ---
//   600cb460 key_value_store__600cb460
//   60100d30 FUN_60100d30
// --- callees ---
//   600d37ac FUN_600d37ac
//   60101740 FUN_60101740


/* src: key_value_store.h */

int key_value_store__600cb210(undefined4 *param_1)

{
  uint uVar1;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 *local_98;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined1 local_8c;
  undefined1 local_8b;
  undefined1 local_8a [130];
  
  uVar1 = (**(code **)(*(int *)*param_1 + 0x10))();
  if (0x40 < uVar1) {
    local_a0 = DAT_600cb268;
    local_9c = 0x118;
    local_98 = local_8a;
    local_94 = 0x80;
    uStack_90 = 0;
    local_8c = 0;
    local_8b = 0;
    local_8a[0] = 0;
    FUN_600d37ac(&local_98,DAT_600cb26c);
    FUN_60101740(&local_a0);
  }
  uVar1 = (**(code **)(*(int *)*param_1 + 0x10))();
  return (0x40 / uVar1) * uVar1;
}


