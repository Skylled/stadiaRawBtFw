// 600d838a  FUN_600d838a  size=50 bytes
// --- callers ---
//   60068698 FUN_60068698
//   600686d4 FUN_600686d4
// --- callees ---
//   600d8322 FUN_600d8322
//   600d835e FUN_600d835e


void FUN_600d838a(undefined4 param_1,undefined4 *param_2,byte param_3)

{
  char cVar1;
  
  cVar1 = FUN_600d8322(param_1,*param_2);
  if (cVar1 == '\0') {
    **(byte **)param_2[1] = (param_3 & 1) << 5 | **(byte **)param_2[1] & 0xdf;
    FUN_600d835e(param_1,*param_2);
  }
  return;
}


