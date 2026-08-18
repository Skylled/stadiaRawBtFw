// 600c5d3c  FUN_600c5d3c  size=106 bytes
// --- callers ---
//   600c5ff4 FUN_600c5ff4
// --- callees ---
//   600c54ec FUN_600c54ec
//   600efcc6 FUN_600efcc6
//   601024d8 FUN_601024d8
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600c5d3c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined1 auStack_12c [6];
  undefined1 auStack_126 [248];
  undefined1 local_2e;
  undefined1 auStack_2c [20];
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(short *)(DAT_600c5da8 + 6) != 0) {
    local_10 = param_1;
    uStack_c = param_2;
    uStack_8 = param_3;
    uStack_4 = param_4;
    FUN_600efcc6(auStack_12c,DAT_600c5dac);
    uVar1 = FUN_600c54ec();
    FUN_601024d8(auStack_126,uVar1,0xf8);
    local_2e = 0;
    thunk_EXT_FUN_0000b572(auStack_2c,&local_10,0x14);
    (*(code *)*DAT_600c5da8)(3,auStack_12c);
  }
  return;
}


