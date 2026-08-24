// 600f204a  FUN_600f204a  size=54 bytes
// --- callers ---
//   600a51a8 FUN_600a51a8
//   600a4c5c FUN_600a4c5c
// --- callees ---


ushort FUN_600f204a(ushort param_1,char param_2)

{
  ushort uVar1;
  
  if (param_2 == '\0') {
    uVar1 = 0x1046;
  }
  else {
    uVar1 = 0x2070;
  }
  return uVar1 | param_1;
}


