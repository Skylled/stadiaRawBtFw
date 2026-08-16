// 600d4330  FUN_600d4330  size=56 bytes
// --- callers ---
//   600d847c FUN_600d847c
//   6005d3b4 thermal__6005d3b4
//   600d8636 FUN_600d8636
//   600d8448 FUN_600d8448
//   60081ab4 gatt_server__60081ab4
//   60068cb4 battery_gauge_bq2742X__60068cb4
// --- callees ---
//   6013d0b0 thunk_EXT_FUN_00001ea4


void FUN_600d4330(undefined4 *param_1,undefined1 param_2,undefined2 *param_3,undefined4 param_4)

{
  char cVar1;
  undefined1 local_10 [4];
  undefined1 local_c;
  undefined1 local_b;
  
  local_10[0] = param_2;
  cVar1 = thunk_EXT_FUN_00001ea4
                    (*param_1,*(undefined1 *)(param_1 + 1),local_10,1,&local_c,2,param_4);
  if (cVar1 == '\0') {
    *param_3 = CONCAT11(local_b,local_c);
  }
  return;
}


