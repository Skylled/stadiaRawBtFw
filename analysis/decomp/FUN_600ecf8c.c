// 600ecf8c  FUN_600ecf8c  size=34 bytes
// --- callers ---
//   600ed09a FUN_600ed09a
//   60091ddc FUN_60091ddc
//   60090fd0 FUN_60090fd0
// --- callees ---
//   6013d208 thunk_EXT_FUN_0000ac5e


void FUN_600ecf8c(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  if (*(char *)((int)param_1 + 0xe) == '\0') {
    puVar1 = (undefined4 *)*param_1;
    if (puVar1 != (undefined4 *)0x0) {
      if (*(char *)(puVar1 + 3) != '\0') {
        thunk_EXT_FUN_0000ac5e(*puVar1);
      }
      thunk_EXT_FUN_0000ac5e(*param_1);
    }
    *param_1 = 0;
  }
  return;
}


