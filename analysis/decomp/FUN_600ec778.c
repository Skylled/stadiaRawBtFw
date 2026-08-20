// 600ec778  FUN_600ec778  size=52 bytes
// --- callers ---
// --- callees ---
//   600ec756 FUN_600ec756


undefined4 FUN_600ec778(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_2c;
  undefined1 local_28;
  
  local_2c = 0;
  if (param_1 == (undefined4 *)0x0) {
    param_1 = &local_2c;
  }
  local_28 = 0;
  iVar1 = FUN_600ec756(param_1);
  if (iVar1 < 1) {
    uVar2 = 0;
  }
  else {
    uVar2 = *param_1;
  }
  return uVar2;
}


