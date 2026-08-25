// 600f70b4  FUN_600f70b4  size=132 bytes
// --- callers ---
//   600f47a0 FUN_600f47a0
//   600f45a6 FUN_600f45a6
// --- callees ---
//   600ffada FUN_600ffada
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined4
FUN_600f70b4(undefined4 param_1,undefined2 param_2,undefined1 param_3,undefined2 param_4,
            undefined2 param_5,undefined2 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  undefined1 auStack_274 [2];
  undefined2 local_272;
  undefined2 local_270;
  undefined2 local_26e;
  undefined1 auStack_26b [607];
  
  local_26e = param_5;
  local_270 = param_6;
  local_272 = param_4;
  thunk_EXT_FUN_0000b572(auStack_26b,param_7,param_5);
  uVar1 = FUN_600ffada(param_1,param_2,param_3,auStack_274);
  return uVar1;
}


