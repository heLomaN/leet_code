vector<Itv> insert(vector<Itv>& sec, Itv itv){
    vector<Itv> nsec;
    int i = 0;
    for (; i < sec.size() && sec[i].end < itv.start; i++){
        nsec.push_back(sec[i]);
    }
    Itv nitv;
    for(; i < sec.size() && sec[i].start < itv.end; i++){
        nitv.start = sec[i].start < itv.start ? sec[i].start : itv.start;
        nitv.end = sec[i].end > itv.end ? sec[i].end : itv.end;
    }
    nsec.push_back(nitv);
    for (; i < sec.size(); i++)
        nsec.push_back(sec[i]);

    return nsec;
}

