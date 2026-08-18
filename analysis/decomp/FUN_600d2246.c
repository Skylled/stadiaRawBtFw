// 600d2246  FUN_600d2246  size=48 bytes
// --- callers ---
//   600569e4 FUN_600569e4
//   600d265a FUN_600d265a
// --- callees ---


undefined4 FUN_600d2246(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    puVar2 = *(undefined4 **)(param_1 + 0x2d4);
    if (param_2 == puVar2) {
      *(undefined4 *)(param_1 + 0x2d4) = *param_2;
    }
    else {
      puVar1 = (undefined4 *)*puVar2;
      do {
        puVar3 = puVar2;
        puVar2 = puVar1;
        if (puVar2 == (undefined4 *)0x0) {
          return 0;
        }
        puVar1 = (undefined4 *)*puVar2;
      } while (puVar2 != param_2);
      *puVar3 = (undefined4 *)*puVar2;
    }
    return 0;
  }
  return 3;
}


