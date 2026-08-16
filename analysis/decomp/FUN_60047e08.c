// 60047e08  FUN_60047e08  size=108 bytes
// --- callers ---
//   60042c9c FUN_60042c9c
// --- callees ---
//   6004bb60 FUN_6004bb60
//   6004c084 thunk_FUN_601016a2
//   6004bb1a FUN_6004bb1a


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_60047e08(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (*_DAT_60047e74 == 0) {
    thunk_FUN_601016a2(_DAT_60047e7c,0xd0f,_DAT_60047e78);
  }
  *param_1 = param_2 | 0x80000000;
  uVar2 = param_1[3];
  if (uVar2 == 0) {
    thunk_FUN_601016a2(_DAT_60047e7c,0xd17,_DAT_60047e78);
  }
  FUN_6004bb60(param_1);
  FUN_6004bb60(uVar2 + 4);
  uVar1 = *(uint *)(uVar2 + 0x2c);
  *_DAT_60047e80 = 1 << (uVar1 & 0xff) | *_DAT_60047e80;
  FUN_6004bb1a(uVar1 * 0x14 + _DAT_60047e84,uVar2 + 4);
  if (*(uint *)(*_DAT_60047e88 + 0x2c) < *(uint *)(uVar2 + 0x2c)) {
    *_DAT_60047e8c = 1;
  }
  return;
}


