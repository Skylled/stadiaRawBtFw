// 600662e0  dynamic_buffer__600662e0  size=136 bytes
// src: dynamic_buffer.h
// --- callers ---
//   60066370 keys__60066370
// --- callees ---
//   601010c8 FUN_601010c8
//   600d6e62 FUN_600d6e62
//   6013d038 thunk_EXT_FUN_00008832
//   600ce2a0 FUN_600ce2a0
//   60101740 FUN_60101740
//   600cb598 key_value_store__600cb598


/* src: dynamic_buffer.h */

uint dynamic_buffer__600662e0(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  ushort local_b2;
  undefined1 auStack_b0 [152];
  
  local_b2 = 0;
  uVar1 = FUN_601010c8(param_1,param_2,&local_b2);
  if ((uVar1 & 0xff) == 0) {
    uVar1 = (uint)local_b2;
    if ((int)uVar1 <= param_3) {
      if (*(uint *)(param_4 + 8) < uVar1) {
        if (*(int *)(param_4 + 4) != 0) {
          FUN_600d6e62(param_4 + 0x10,param_4);
        }
        *(undefined4 *)(param_4 + 8) = 0;
        *(undefined4 *)(param_4 + 0xc) = 0;
        iVar2 = thunk_EXT_FUN_00008832(uVar1);
        *(int *)(param_4 + 4) = iVar2;
        if (iVar2 == 0) {
          FUN_600ce2a0(auStack_b0,DAT_6006636c,DAT_60066368,0x6d);
          FUN_60101740(auStack_b0);
        }
        *(uint *)(param_4 + 8) = uVar1;
        *(uint *)(param_4 + 0xc) = uVar1;
      }
      else {
        *(uint *)(param_4 + 0xc) = uVar1;
      }
      if (*(int *)(param_4 + 4) != 0) {
        uVar1 = key_value_store__600cb598(param_1,param_2,*(int *)(param_4 + 4),local_b2,0);
        return uVar1;
      }
    }
    uVar1 = 0xf;
  }
  return uVar1;
}


