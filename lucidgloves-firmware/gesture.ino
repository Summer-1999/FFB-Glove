bool grab=0;
bool pinch=0;
bool trigger=0; 

bool grabGesture(int *flexion){
  if (grab == 0){
    grab = (flexion[PINKY_IND] + flexion[RING_IND] + flexion[MIDDLE_IND] + flexion[INDEX_IND]) / 4 > ANALOG_MAX/2 ? 1:0;
  }
  else{
    grab = (flexion[PINKY_IND] + flexion[RING_IND] + flexion[MIDDLE_IND] + flexion[INDEX_IND]) / 4 <= ANALOG_MAX/10 ? 0:1;
  }
  return grab;
}

bool pinchGesture(int *flexion){
  if (pinch == 0) {
      pinch = (flexion[INDEX_IND] + flexion[THUMB_IND]) / 2 > ANALOG_MAX/2 ? 1:0;
  }
  else {
      pinch = (flexion[INDEX_IND] + flexion[THUMB_IND]) / 2 < ANALOG_MAX/4 ? 0:1;
  }
  return pinch;
}

bool triggerGesture(int *flexion){
  if (trigger == 0){
    trigger = flexion[INDEX_IND]>(ANALOG_MAX/2)?1:0;
  }
  else{
    trigger = flexion[INDEX_IND]<(ANALOG_MAX/8)?0:1;
  }
  return trigger;
}
