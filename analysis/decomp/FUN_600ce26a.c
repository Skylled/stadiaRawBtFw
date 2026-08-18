// 600ce26a  FUN_600ce26a  size=54 bytes
// --- callers ---
//   60051240 main__60051240
//   6005c570 FUN_6005c570
//   6005be94 FUN_6005be94
// --- callees ---
//   6013cf40 thunk_EXT_FUN_00007d10
//   6007f8e4 pattern_player__6007f8e4
//   6013d3d8 thunk_EXT_FUN_0000b4c2


void FUN_600ce26a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = param_3;
  thunk_EXT_FUN_0000b4c2();
  pattern_player__6007f8e4(param_1,param_2,param_3,0,param_4,param_5,uVar1);
  thunk_EXT_FUN_00007d10(param_1);
  return;
}


