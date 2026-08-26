// 60100ad0  FUN_60100ad0  size=58 bytes
// --- callers ---
//   600cafec FUN_600cafec
// --- callees ---


undefined4 FUN_60100ad0(uint param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 1 << ((param_2 & 0x3f) >> 1) + 1;
  if ((uVar2 < 0x20) ||
     ((((param_2 & 0xff00) != 0 && (uVar2 < 0x81)) || ((uVar2 & uVar2 - 1) != 0)))) {
    uVar1 = 0;
  }
  else if ((param_1 & uVar2 - 1) == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


