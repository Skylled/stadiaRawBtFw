// 600ddb2a  FUN_600ddb2a  size=24 bytes
// --- callers ---
//   600dd83c FUN_600dd83c
// --- callees ---


void FUN_600ddb2a(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  *param_1 = *(undefined4 *)(param_2 + 0x18);
  puVar1 = param_1 + 1;
  do {
    puVar2 = puVar1 + 1;
    *puVar1 = 0;
    puVar1 = puVar2;
  } while (puVar2 != param_1 + 0x40);
  return;
}


