// 600c6654  FUN_600c6654  size=142 bytes
// --- callers ---
// --- callees ---
//   600efcc6 FUN_600efcc6
//   600962dc FUN_600962dc
//   600f7c42 FUN_600f7c42
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6006dbac FUN_6006dbac


void FUN_600c6654(undefined1 param_1,undefined4 param_2,undefined2 param_3,char param_4,
                 undefined2 param_5,undefined1 param_6)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  
  puVar2 = (undefined2 *)FUN_6006dbac(0x124,DAT_600c66e4,0x6c8);
  if (puVar2 != (undefined2 *)0x0) {
    thunk_EXT_FUN_0000b5ba(puVar2,0,0x124);
    if (param_4 == '\0') {
      uVar3 = 0x1d11;
    }
    else {
      uVar3 = 0x1d0d;
    }
    *puVar2 = uVar3;
    puVar2[3] = param_3;
    *(undefined1 *)(puVar2 + 7) = param_1;
    uVar1 = FUN_600f7c42(param_2);
    *(undefined1 *)((int)puVar2 + 0xf) = uVar1;
    puVar2[9] = param_5;
    *(undefined1 *)(puVar2 + 8) = param_6;
    FUN_600efcc6(puVar2 + 4,param_2);
    FUN_600962dc(puVar2);
  }
  return;
}


