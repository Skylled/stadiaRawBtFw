// 600d87c0  FUN_600d87c0  size=52 bytes
// --- callers ---
//   60068cb4 battery_gauge_bq2742X__60068cb4
// --- callees ---
//   600d855e FUN_600d855e
//   600d8778 FUN_600d8778
//   60068b80 battery_gauge_bq2742X__60068b80
//   600d8722 FUN_600d8722


void FUN_600d87c0(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_600d8778();
  if (((cVar1 == '\0') && (cVar1 = battery_gauge_bq2742X__60068b80(param_1), cVar1 == '\0')) &&
     ((*(char *)(param_1 + 0x1b) != '\x01' || (cVar1 = FUN_600d855e(param_1), cVar1 == '\0')))) {
    FUN_600d8722(param_1);
  }
  return;
}


