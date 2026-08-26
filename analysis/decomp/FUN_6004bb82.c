// 6004bb82  FUN_6004bb82  size=22 bytes
// --- callers ---
//   60047548 FUN_60047548
//   60047678 queue__60047678
// --- callees ---
//   60048580 FUN_60048580
//   600485c8 FUN_600485c8


bool FUN_6004bb82(int param_1)

{
  int iVar1;
  
  FUN_60048580();
  iVar1 = *(int *)(param_1 + 0x38);
  FUN_600485c8();
  return iVar1 == 0;
}


