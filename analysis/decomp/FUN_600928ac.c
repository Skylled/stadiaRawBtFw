// 600928ac  FUN_600928ac  size=94 bytes
// --- callers ---
// --- callees ---
//   600927d8 FUN_600927d8
//   60092838 FUN_60092838
//   600ee1be FUN_600ee1be
//   600ee1fe FUN_600ee1fe


undefined1 FUN_600928ac(undefined2 param_1,undefined4 param_2)

{
  undefined1 local_9;
  
  local_9 = 1;
  switch(param_1) {
  case 5:
    local_9 = FUN_600ee1be(param_2);
    break;
  case 6:
  case 7:
    local_9 = FUN_600ee1fe(param_1,param_2);
    break;
  case 8:
    local_9 = FUN_600927d8(param_2);
    break;
  case 9:
    FUN_60092838(param_2);
    break;
  default:
    local_9 = 0;
  }
  return local_9;
}


