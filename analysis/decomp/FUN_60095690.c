// 60095690  FUN_60095690  size=108 bytes
// --- callers ---
//   6006a944 gatt_server__6006a944
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6006dbac FUN_6006dbac
//   600962dc FUN_600962dc


void FUN_60095690(undefined1 param_1,undefined4 param_2,undefined1 param_3,undefined2 param_4,
                 undefined1 param_5)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x24,DAT_600956fc,0x97);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = 0x1e03;
    *(undefined1 *)(puVar1 + 4) = param_1;
    *(undefined1 *)(puVar1 + 0x11) = param_3;
    thunk_EXT_FUN_0000b572(puVar1 + 6,param_2,0x14);
    puVar1[0x10] = param_4;
    *(undefined1 *)((int)puVar1 + 0x23) = param_5;
    FUN_600962dc(puVar1);
  }
  return;
}


